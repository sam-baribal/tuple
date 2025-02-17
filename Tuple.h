#ifndef T_TUPLE_H
#define T_TUPLE_H

namespace tpl {
  /* namespace details {
    struct tupleItem
    {
      void* value;
      char* type;
    };
  } */
  

  template<typename T, typename ... Types>
  class Tuple {
  private:
    size_t size;
    std::variant<Types ...> tab [];

  public:
    /**
     * Default constructor
     */
    Tuple() {
      size = 0;
      tab = NULL;
    }

    /**
     * Constructor to initialize values
     */
    Tuple(Types&& ... values) {
      size = sizeof...(values);
      tab = calloc(size, sizeof(std::variant<Types ...>));
      size_t i = 0;
      for (auto&& x : {values ...}) {
        tab[i] = x;
        i++;
        if (i == size){break;}
      }
    } 

    /**
     * Value getter
     *
     * --> iterate on itself while index >= 0
     * return type is not definitive yet
     */
    template<int index>
    const auto& get() const {
      
    }

    template<int index>
    auto& get() {

    }

    /**
     * Addition between to tuples
     */
    template <typename ... OtherTypes>
    Tuple</* implementation defined */>& operator+(const Tuple<OtherTypes...>& other) const {

    }

    /**
     * Addition between to tuples - in place
     */
    template <typename ... OtherTypes>
    Tuple</* implementation defined */> operator+=(const Tuple<OtherTypes...>& other) {

    }

    /**
     * Substraction between to tuples
     */
    template <typename ... OtherTypes>
    Tuple</* implementation defined */> operator-(const Tuple<OtherTypes...>& other) const {

    }

    /**
     * Substraction between to tuples - in place
     */
    template <typename ... OtherTypes>
    Tuple</* implementation defined */>& operator-=(const Tuple<OtherTypes...>& other) {

    }

    /**
     * Multiplication between to tuples
     */
    template <typename ... OtherTypes>
    Tuple</* implementation defined */> operator*(const Tuple<OtherTypes...>& other) const {

    }

    /**
     * Multiplication between to tuples - in place
     */
    template <typename ... OtherTypes>
    Tuple</* implementation defined */>& operator*=(const Tuple<OtherTypes...>& other) {

    }

    /**
     * Division between to tuples
     */
    template <typename ... OtherTypes>
    Tuple</* implementation defined */> operator/(const Tuple<OtherTypes...>& other) const {

    }

    /**
     * Division between to tuples - in place
     */
    template <typename ... OtherTypes>
    Tuple</* implementation defined */>& operator/=(const Tuple<OtherTypes...>& other) {

    }

    /**
     * Comparaison operators
     */
    template <typename ... OtherTypes>
    bool operator==(const Tuple<OtherTypes...>& other) const {

    }

    template <typename ... OtherTypes>
    bool operator!=(const Tuple<OtherTypes...>& other) const {

    }

    template <typename ... OtherTypes>
    bool operator<(const Tuple<OtherTypes...>& other) const {

    }

    template <typename ... OtherTypes>
    bool operator<=(const Tuple<OtherTypes...>& other) const {

    }

    template <typename ... OtherTypes>
    bool operator>(const Tuple<OtherTypes...>& other) const {

    }

    template <typename ... OtherTypes>
    bool operator>=(const Tuple<OtherTypes...>& other) const {

    }

    /**
     * Concatenate two tuples
     */
    template <typename ... OtherTypes>
    Tuple</* implementation defined */> operator|(Tuple<OtherTypes...>&& other) {

    }
  };

  /**
   * Helper function to create a tuple
   */
  template <class... Types>
  constexpr Tuple<Types...> makeTuple(Types&&... args) {

  }

}

#endif // T_TUPLE_H
