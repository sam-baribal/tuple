#ifndef T_TUPLE_H
#define T_TUPLE_H

namespace tpl {
  template<typename ... Types>
  class Tuple {
  private:
    size_t size;
    std::vector<std::variant<Types...>> tab;

    template <typename FirstT, typename ... RestTypes>
    void recursiveConstruction(FirstT firstVal, RestTypes... restVals) {
      tab.push_back(firstVal);
      recursiveConstruction<RestTypes...>(restVals...);
    }

    template <typename LastT>
    void recursiveConstruction(LastT lastVal) {
      tab.push_back(lastVal);
    }

  public:
    /**
     * Default constructor
     */
    Tuple() {
      size = 0;
      tab = {};
    }

    /**
     * Constructor to initialize values
     */
    Tuple(Types... values) {
      size = sizeof...(values);
      tab = {};
      recursiveConstruction<Types...>(values...);
    } 

    /**
     * Value getter
     */
    template<int index>
    const auto& get() const {
      std::cout << "get const\n";
      return std::get<index>(tab.at(index));
    }

    template<int index>
    auto& get() {
      std::cout << "get pas const\n";
      return std::get<index>(tab.at(index));
    }
    
    /**
     * Addition between to tuples
     */
    template <typename ... OtherTypes>
    Tuple<Types ...> operator+(const Tuple<OtherTypes...>& other) const {
      return NULL;
    }

    /**
     * Addition between to tuples - in place
     */
    template <typename ... OtherTypes>
    Tuple<Types ...>& operator+=(const Tuple<OtherTypes...>& other) {
      return NULL;
    }

    /**
     * Substraction between to tuples
     */
    template <typename ... OtherTypes>
    Tuple<Types ...> operator-(const Tuple<OtherTypes...>& other) const {
      return NULL;
    }

    /**
     * Substraction between to tuples - in place
     */
    template <typename ... OtherTypes>
    Tuple<Types ...>& operator-=(const Tuple<OtherTypes...>& other) {
      return NULL;
    }

    /**
     * Multiplication between to tuples
     */
    template <typename ... OtherTypes>
    Tuple<Types ...> operator*(const Tuple<OtherTypes...>& other) const {
      return NULL;
    }

    /**
     * Multiplication between to tuples - in place
     */
    template <typename ... OtherTypes>
    Tuple<Types ...>& operator*=(const Tuple<OtherTypes...>& other) {
      return NULL;
    }

    /**
     * Division between to tuples
     */
    template <typename ... OtherTypes>
    Tuple<Types ...> operator/(const Tuple<OtherTypes...>& other) const {
      return NULL;
    }

    /**
     * Division between to tuples - in place
     */
    template <typename ... OtherTypes>
    Tuple<Types ...>& operator/=(const Tuple<OtherTypes...>& other) {
      return NULL;
    }

    /**
     * Comparaison operators
     */
    template <typename ... OtherTypes>
    bool operator==(const Tuple<OtherTypes...>& other) const {
      return false;
    }

    template <typename ... OtherTypes>
    bool operator!=(const Tuple<OtherTypes...>& other) const {
      return false;
    }

    template <typename ... OtherTypes>
    bool operator<(const Tuple<OtherTypes...>& other) const {
      return false;
    }

    template <typename ... OtherTypes>
    bool operator<=(const Tuple<OtherTypes...>& other) const {
      return false;
    }

    template <typename ... OtherTypes>
    bool operator>(const Tuple<OtherTypes...>& other) const {
      return false;
    }

    template <typename ... OtherTypes>
    bool operator>=(const Tuple<OtherTypes...>& other) const {
      return false;
    }

    /**
     * Concatenate two tuples
     */
    template <typename ... OtherTypes>
    Tuple<Types ...> operator|(Tuple<OtherTypes...>&& other) {

    }
  };

  /**
   * Helper function to create a tuple
   */
  template <class... Types>
  constexpr Tuple<Types...> makeTuple(Types&&... args) {
    Tuple<Types...> res(args...);
    return res;
  }

}

#endif // T_TUPLE_H
