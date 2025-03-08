#ifndef T_TUPLE_H
#define T_TUPLE_H

#include <typeinfo>
#include <variant>
#include <sys/types.h>
#include <stdio.h>


namespace tpl {
  
template<typename ...Types>
class Tuple  {
  private:
    size_t size;
  public:
    template <typename ...U> friend class Tuple;
    /**
     * Default constructor
     */
    Tuple() {
        size = 0;
    }

    /**
     * Addition between to tuples
     */
    template <typename ... OtherTypes>
    Tuple<Types ...> operator+(const Tuple<OtherTypes...>& other) const {
        Tuple<Types ...> res = *this;
        res += other;
        return res;
    }

    /**
     * Addition between to tuples - in place
     */
    template <typename ... OtherTypes>
    Tuple<Types ...>& operator+=(const Tuple<OtherTypes...>& other) {
        (void) (other.size == 0);
        return *this;
    }

    /**
     * Substraction between to tuples
     */
    template <typename ... OtherTypes>
    Tuple<Types ...> operator-(const Tuple<OtherTypes...>& other) const {
        Tuple<Types ...> res = *this;
        res -= other;
        return res;
    }

    /**
     * Substraction between to tuples - in place
     */
    template <typename ... OtherTypes>
    Tuple<Types ...>& operator-=(const Tuple<OtherTypes...>& other) {
        (void) (other.size == 0);
        return *this;
    }

    /**
     * Multiplication between to tuples
     */
    template <typename ... OtherTypes>
    Tuple<Types ...> operator*(const Tuple<OtherTypes...>& other) const {
        Tuple<Types ...> res = *this;
        res *= other;
        return res;
    }

    /**
     * Multiplication between to tuples - in place
     */
    template <typename ... OtherTypes>
    Tuple<Types ...>& operator*=(const Tuple<OtherTypes...>& other) {
        (void) (other.size == 0);
        return *this;
    }

    /**
     * Division between to tuples
     */
    template <typename ... OtherTypes>
    Tuple<Types ...> operator/(const Tuple<OtherTypes...>& other) const {
        Tuple<Types ...> res = *this;
        res /= other;
        return res;
    }

    /**
     * Division between to tuples - in place
     */
    template <typename ... OtherTypes>
    Tuple<Types ...>& operator/=(const Tuple<OtherTypes...>& other) {
        (void) (other.size == 0);
        return *this;
    }

    /**
     * Comparaison operators
     */
    template <typename ... OtherTypes>
    bool operator==(const Tuple<OtherTypes...>& other) const {
      return other.size == 0;
    }

    template <typename ... OtherTypes>
    bool operator!=(const Tuple<OtherTypes...>& other) const {
      return other.size != 0;
    }

    template <typename ... OtherTypes>
    bool operator<(const Tuple<OtherTypes...>& other) const {
      (void) other;
      return false;
    }

    template <typename ... OtherTypes>
    bool operator<=(const Tuple<OtherTypes...>& other) const {
      return other.size == 0;
    }

    template <typename ... OtherTypes>
    bool operator>(const Tuple<OtherTypes...>& other) const {
      return other.size != 0;
    }

    template <typename ... OtherTypes>
    bool operator>=(const Tuple<OtherTypes...>& other) const {
      (void) other;
      return true;
    }

    /**
     * Concatenate two tuples
     */
    template <typename ... OtherTypes>
    Tuple<OtherTypes ...> operator|(Tuple<OtherTypes...>&& other) {
        return other;
    }
  };
  
template<typename Type, typename ...Types>
class Tuple<Type, Types ...> {
  private:
    size_t size;
    Type item;
    Tuple<Types...> next;
    
    
    Tuple(Type head, Tuple<Types ...> queue): item (head), next (queue){
      size = queue.size + 1;
    }
    
  public:
    template <typename ...U> friend class Tuple;
    /**
     * Constructor to initialize values
     */
    Tuple(Type head, Types ...queue): item (head), next (Tuple<Types...> (queue...)){
      size = sizeof... (queue) + 1;
    }

    /**
     * Value getter
     */
    template<int index>
    const auto& get() const {
      if constexpr (index > 0){
        return next.template get<index-1> ();
      }
      if constexpr (index == 0){
        return item;
      }
      if constexpr (index < 0){
        return NULL;
      }
    }
    
    
    template<int index>
    auto& get() {
      if constexpr (index > 0){
        return next.template get<index-1> ();
      }
      if constexpr (index == 0){
        return item;
      }
      if constexpr (index < 0){
        return NULL;
      }
    }

    /**
     * Addition between to tuples
     */
    template <typename ... OtherTypes>
    Tuple<Type, Types ...> operator+(const Tuple<OtherTypes...>& other) const {
        Tuple<Type, Types ...> res = *this;
        res += other;
        return res;
    }

    /**
     * Addition between to tuples - in place
     */
    template <typename ... OtherTypes>
    Tuple<Type, Types ...>& operator+=(const Tuple<OtherTypes...>& other) {
        item += other.item;
        next += other.next;
        return *this;
    }

    /**
     * Substraction between to tuples
     */
    template <typename ... OtherTypes>
    Tuple<Type, Types ...> operator-(const Tuple<OtherTypes...>& other) const {
        Tuple<Type, Types ...> res = *this;
        res -= other;
        return res;
    }

    /**
     * Substraction between to tuples - in place
     */
    template <typename ... OtherTypes>
    Tuple<Type, Types ...>& operator-=(const Tuple<OtherTypes...>& other) {
        item -= other.item;
        next -= other.next;
        return *this;
    }

    /**
     * Multiplication between to tuples
     */
    template <typename ... OtherTypes>
    Tuple<Type, Types ...> operator*(const Tuple<OtherTypes...>& other) const {
        Tuple<Type, Types ...> res = *this;
        res *= other;
        return res;
    }

    /**
     * Multiplication between to tuples - in place
     */
    template <typename ... OtherTypes>
    Tuple<Type, Types ...>& operator*=(const Tuple<OtherTypes...>& other) {
        item *= other.item;
        next *= other.next;
        return *this;
    }

    /**
     * Division between to tuples
     */
    template <typename ... OtherTypes>
    Tuple<Type, Types ...> operator/(const Tuple<OtherTypes...>& other) const {
        Tuple<Type, Types ...> res = *this;
        res /= other;
        return res;
    }

    /**
     * Division between to tuples - in place
     */
    template <typename ... OtherTypes>
    Tuple<Type, Types ...>& operator/=(const Tuple<OtherTypes...>& other) {
        item /= other.item;
        next /= other.next;
        return *this;
    }

    /**
     * Comparaison operators
     */
    template <typename ... OtherTypes>
    bool operator==(const Tuple<OtherTypes...>& other) const {
      return size == other.size && (item == other.item && next == other.next);
    }

    template <typename ... OtherTypes>
    bool operator!=(const Tuple<OtherTypes...>& other) const {
      return size != other.size || (item != other.item || next != other.next);
    }

    template <typename ... OtherTypes>
    bool operator<(const Tuple<OtherTypes...>& other) const {
      return (!(other.size == 0)) && (item < other.item || (item == other.item && next < other.next));
    }

    template <typename ... OtherTypes>
    bool operator<=(const Tuple<OtherTypes...>& other) const {
      return (!(other.size == 0)) && (item < other.item || (item == other.item && next <= other.next));
    }

    template <typename ... OtherTypes>
    bool operator>(const Tuple<OtherTypes...>& other) const {
      return other.size == 0 || (item > other.item || (item == other.item && next > other.next));
    }

    template <typename ... OtherTypes>
    bool operator>=(const Tuple<OtherTypes...>& other) const {
      return other.size == 0 || (item > other.item || (item == other.item && next >= other.next));
    }

    /**
     * Concatenate two tuples
     */
    template <typename ... OtherTypes>
    Tuple<Type, Types..., OtherTypes...> operator|(Tuple<OtherTypes...>&& other) {
      Tuple<Types..., OtherTypes...> next_tuple = (std::move (next) | std::move (other));
      Tuple<Type, Types..., OtherTypes...> res (item, next_tuple);
      return res;
    }
  };

  /**
   * Helper function to create a tuple
   */
  template <class... Types>
  constexpr Tuple<Types...> makeTuple(Types&&... args) {
    return Tuple<Types...> (args ...);
  }
  
}
#endif // T_TUPLE_H
