#!/usr/bin/env bash
# Prepare le projet : installe la CSFML 2.6 puis compile le jeu.
# A lancer une seule fois, depuis n'importe quel dossier : ./install.sh
set -euo pipefail

SFML_VERSION="2.6.1"
CSFML_VERSION="2.6.1"
BASE_URL="https://github.com/SFML"
REPO_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
DEPS_DIR="$REPO_DIR/.deps"

fail() {
    echo >&2
    echo "ERREUR : $1" >&2
    echo "Envoie cette fenetre entiere a Stanislas." >&2
    exit 1
}

wait_for_xcode_tools() {
    if xcode-select -p >/dev/null 2>&1; then
        return
    fi
    echo "Une fenetre va s'ouvrir : clique sur Installer et laisse faire."
    echo "Le script reprendra tout seul a la fin, ne ferme pas cette fenetre."
    xcode-select --install >/dev/null 2>&1 || true
    until xcode-select -p >/dev/null 2>&1; do
        sleep 10
    done
}

download() {
    local url="$1"
    local dest="$2"

    mkdir -p "$dest"
    curl -fL --retry 3 --progress-bar "$url" -o "$DEPS_DIR/archive.tar.gz" ||
        fail "telechargement impossible, verifie ta connexion internet."
    tar xzf "$DEPS_DIR/archive.tar.gz" -C "$dest" --strip-components=1
    rm -f "$DEPS_DIR/archive.tar.gz"
}

install_macos() {
    local major
    local minor
    local arch

    major="$(sw_vers -productVersion | cut -d. -f1)"
    minor="$(sw_vers -productVersion | cut -d. -f2)"
    if [[ "$major" -eq 10 && "$minor" -lt 15 ]]; then
        fail "macOS $(sw_vers -productVersion) est trop ancien (minimum : 10.15)."
    fi
    case "$(uname -m)" in
        arm64) arch="arm64" ;;
        x86_64) arch="64-bit" ;;
        *) fail "processeur non gere : $(uname -m)." ;;
    esac
    wait_for_xcode_tools
    if [[ -d "$DEPS_DIR/lib" ]]; then
        echo "CSFML deja presente."
        return
    fi
    echo "Telechargement de la CSFML..."
    rm -rf "$DEPS_DIR"
    mkdir -p "$DEPS_DIR/Frameworks"
    download "$BASE_URL/SFML/releases/download/$SFML_VERSION/SFML-$SFML_VERSION-macOS-clang-$arch.tar.gz" "$DEPS_DIR/sfml"
    download "$BASE_URL/CSFML/releases/download/$CSFML_VERSION/CSFML-$CSFML_VERSION-macOS-clang-$arch.tar.gz" "$DEPS_DIR/csfml"
    mv "$DEPS_DIR/csfml/include" "$DEPS_DIR/csfml/lib" "$DEPS_DIR/"
    mv "$DEPS_DIR"/sfml/Frameworks/* "$DEPS_DIR"/sfml/extlibs/*.framework "$DEPS_DIR/Frameworks/"
    rm -rf "$DEPS_DIR/sfml" "$DEPS_DIR/csfml"
}

install_linux() {
    if command -v apt-get >/dev/null 2>&1; then
        sudo apt-get update
        sudo apt-get install -y build-essential libcsfml-dev
    elif command -v dnf >/dev/null 2>&1; then
        sudo dnf install -y gcc make CSFML-devel
    else
        fail "Linux detecte, mais seuls apt et dnf sont geres."
    fi
}

case "$(uname -s)" in
    Darwin) install_macos ;;
    Linux) install_linux ;;
    *) fail "systeme non gere : $(uname -s). Il faut macOS ou Linux." ;;
esac

echo "Compilation du jeu..."
if ! BUILD_LOG="$(make -C "$REPO_DIR" re 2>&1)"; then
    echo "$BUILD_LOG" >&2
    fail "la compilation a echoue."
fi

echo
echo "C'est pret ! Pour lancer le jeu : make compile"
