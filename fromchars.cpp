#include <iostream>
#include <charconv>
#include <array>
#include <string>
#include <cerrno>
#include <cstdlib>

int main()
{
  /* FROM_CHARS */
  std::array<char, 10> str{"42 rwk "};
  int result;

  if (auto [p, ec] = std::from_chars(str.data(), str.data()+str.size(), result); ec == std::errc())
    std::cout << result << "\n" "p -> \"" << p << "\"\n" << std::endl;

  /* STRTOF */
  const char *pp = "111.11 -2.22 0X1.BC70A3D70A3D7P+6  1.18973e+4932zzz";
  char *end;
  
  std::cout << "Parsing \"" << pp << "\":\n";

  for (float f = std::strtof(pp, &end); pp != end; f = std::strtof(pp, &end)) {
    std::cout << "  '" << std::string(pp, end-pp) << "' -> ";
    pp = end;

    if (errno == ERANGE) {
      std::cout << "Range error, got ";
      errno = 0;
    }

    std::cout << f << std::endl;
  }
}
