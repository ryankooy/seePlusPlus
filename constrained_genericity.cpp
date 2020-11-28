template<typename T>
struct can_eat {
  private:
    template<typename U, void (U::*)()> struct SFINAE {};
    template<typename U> static char Test(SFINAE<U, &U::eat>*);
    template<typename U> static int Test(...);
  public:
    static constexpr bool value = sizeof(Test<T>(0)) == sizeof(char);
};

struct potato {
  void eat();
};

struct brick {};

template<typename T>
class FoodBox {
  static_assert(can_eat<T>::value,
    "Only edible items are allowed in foodbox");
};

int main()
{
  FoodBox<potato> lunch;
}