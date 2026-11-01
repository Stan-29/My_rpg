#!/usr/bin/env bash
# Installe tout ce qu'il faut pour compiler my_rpg (macOS uniquement).
# Le jeu utilise CSFML 2.6 : Homebrew ne propose que CSFML 3, incompatible,
# d'ou la formule scripts/csfml@2.rb installee dans un tap local.
set -euo pipefail

TAP="my-rpg/local"
FORMULA="csfml@2"
REPO_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

load_brew() {
    for prefix in /opt/homebrew /usr/local; do
        if [[ -x "$prefix/bin/brew" ]]; then
            eval "$("$prefix/bin/brew" shellenv)"
            return 0
        fi
    done
    return 1
}

if [[ "$(uname -s)" != "Darwin" ]]; then
    echo "Erreur : ce script ne gere que macOS." >&2
    exit 1
fi

if ! xcode-select -p >/dev/null 2>&1; then
    echo "Outils Xcode manquants : valide la fenetre qui s'ouvre, puis relance ce script."
    xcode-select --install
    exit 1
fi

if ! command -v brew >/dev/null 2>&1 && ! load_brew; then
    echo "Installation de Homebrew (ton mot de passe de session sera demande)..."
    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
    load_brew
    echo "eval \"\$($(brew --prefix)/bin/brew shellenv)\"" >> "$HOME/.zprofile"
fi

if brew list --versions "$FORMULA" >/dev/null 2>&1; then
    echo "CSFML 2.6 est deja installee."
elif brew list --versions csfml >/dev/null 2>&1; then
    echo "Erreur : CSFML 3 est installee et entre en conflit avec CSFML 2.6." >&2
    echo "Retire-la avec : brew uninstall csfml" >&2
    exit 1
else
    if ! brew tap | grep -qx "$TAP"; then
        brew tap-new --no-git "$TAP"
    fi
    cp "$REPO_DIR/scripts/$FORMULA.rb" "$(brew --repo "$TAP")/Formula/"
    echo "Installation de CSFML 2.6 (compilation, quelques minutes)..."
    brew install "$TAP/$FORMULA"
fi

echo "C'est pret. Lance le jeu avec : make compile"
