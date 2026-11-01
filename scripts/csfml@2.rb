class CsfmlAT2 < Formula
  desc "SFML bindings for C (2.x API, <SFML/*.h>)"
  homepage "https://www.sfml-dev.org/"
  url "https://github.com/SFML/CSFML/archive/refs/tags/2.6.1.tar.gz"
  sha256 "f3f3980f6b5cad85b40e3130c10a2ffaaa9e36de5f756afd4aacaed98a7a9b7b"
  license "Zlib"

  depends_on "cmake" => :build
  depends_on "sfml@2"

  conflicts_with "csfml", because: "both install libcsfml-* libraries"

  def install
    system "cmake", "-S", ".", "-B", "build",
           "-DCSFML_BUILD_DOC=OFF",
           "-DCMAKE_PREFIX_PATH=#{Formula["sfml@2"].opt_prefix}",
           *std_cmake_args
    system "cmake", "--build", "build"
    system "cmake", "--install", "build"
  end

  test do
    (testpath/"test.c").write <<~C
      #include <SFML/Graphics.h>
      int main(void) {
        sfConvexShape *s = sfConvexShape_create();
        sfConvexShape_destroy(s);
        return 0;
      }
    C
    system ENV.cc, "test.c", "-I#{include}", "-L#{lib}", "-lcsfml-graphics", "-o", "test"
    system "./test"
  end
end
