#ifndef T_TUPLE_H
#define T_TUPLE_H

namespace tpl {
  template <typename... Types>
  class Tuple;

  template<typename T, typename... Types>
  class Tuple<T, Types...> {
    private:

    public:
      int size;
      T value;
      Tuple<Types...> next;

      /**
       * Default constructor
       */
      Tuple(){
        int size = 0;
        value = NULL;
        next = NULL;
      }

      Tuple(T&& firstValue, Types&&... restVals)
        : value(std::forward<T>(firstValue)), next(std::forward<Types>(restVals)...) {}
      /*{
        value = std::forward<T>(firstValue);
        if (sizeof...(restVals) == 0){
          next = NULL;
          size = 1;
        }
        else {
          next = std::forward<Types>(restVals)...;
          size = 1 + next.size;
        }
      }*/

      /**
      * Value getter
      */
      template<int index>
      const auto& get() const {
        if constexpr (index == 0){
          return value;
        }
        return next.template get<index-1>();;
      }

      template<int index>
      auto& get() {
        if constexpr (index == 0){
          return value;
        }
        return next.template get<index-1>();
      }
      
      /**
      * Addition between to tuples
      */
      template <typename ... OtherTypes>
      Tuple<Types ...> operator+(const Tuple<OtherTypes...>& other) const {
        return Tuple<Types ...>();
      }

      /**
      * Addition between to tuples - in place
      */
      template <typename ... OtherTypes>
      Tuple<Types ...>& operator+=(const Tuple<OtherTypes...>& other) {
        return Tuple<Types ...>();
      }

      /**
      * Substraction between to tuples
      */
      template <typename ... OtherTypes>
      Tuple<Types ...> operator-(const Tuple<OtherTypes...>& other) const {
        return Tuple<Types ...>();
      }

      /**
      * Substraction between to tuples - in place
      */
      template <typename ... OtherTypes>
      Tuple<Types ...>& operator-=(const Tuple<OtherTypes...>& other) {
        return Tuple<Types ...>();
      }

      /**
      * Multiplication between to tuples
      */
      template <typename ... OtherTypes>
      Tuple<Types ...> operator*(const Tuple<OtherTypes...>& other) const {
        return Tuple<Types ...>();
      }

      /**
      * Multiplication between to tuples - in place
      */
      template <typename ... OtherTypes>
      Tuple<Types ...>& operator*=(const Tuple<OtherTypes...>& other) {
        return Tuple<Types ...>();
      }

      /**
      * Division between to tuples
      */
      template <typename ... OtherTypes>
      Tuple<Types ...> operator/(const Tuple<OtherTypes...>& other) const {
        return Tuple<Types ...>();
      }

      /**
      * Division between to tuples - in place
      */
      template <typename ... OtherTypes>
      Tuple<Types ...>& operator/=(const Tuple<OtherTypes...>& other) {
        return Tuple<Types ...>();
      }

      /**
      * Comparaison operators
      */
      template <typename ... OtherTypes>
      bool operator==(const Tuple<OtherTypes...>& other) const {
        if (size + other.size == 0){
          return true;
        }
        return false;
      }



      template <typename ... OtherTypes>
      bool operator!=(const Tuple<OtherTypes...>& other) const {
        if (size + other.size == 0){
          return true;
        }
        return false;
      }

      template <typename ... OtherTypes>
      bool operator<(const Tuple<OtherTypes...>& other) const {
        if (size + other.size == 0){
          return true;
        }
        return false;
      }

      template <typename ... OtherTypes>
      bool operator<=(const Tuple<OtherTypes...>& other) const {
        if (size + other.size == 0){
          return true;
        }
        return false;
      }

      template <typename ... OtherTypes>
      bool operator>(const Tuple<OtherTypes...>& other) const {
        if (size + other.size == 0){
          return true;
        }
        return false;
      }

      template <typename ... OtherTypes>
      bool operator>=(const Tuple<OtherTypes...>& other) const {
        if (size + other.size == 0){
          return true;
        }
        return false;
      }

      /**
      * Concatenate two tuples
      */
      template <typename ... OtherTypes>
      Tuple<Types ...> operator|(Tuple<OtherTypes...>&& other) {

      }
  };

  template <>
  class Tuple<> {};

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
