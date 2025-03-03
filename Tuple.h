#ifndef T_TUPLE_H
#define T_TUPLE_H

#include <typeinfo>
#include <variant>
#include <sys/types.h>
#include <stdio.h>

namespace tpl {
  /*
  struct tuple_item {
    std::type_info type;
    void *item;
  };*/
  
  template<typename ...Types>
  class Tuple  {
  private:
    size_t size;
  public:
    /**
     * Default constructor
     */
    Tuple() {
        size = 0;
        std::cerr << "Nbarg : 0\n";
    }

    /**
     * Addition between to tuples
     * /
    template <typename ... OtherTypes>
    Tuple<Types ...> operator+(const Tuple<OtherTypes...>& other) const {

    }

    /**
     * Addition between to tuples - in place
     * /
    template <typename ... OtherTypes>
    Tuple<Types ...>& operator+=(const Tuple<OtherTypes...>& other) {

    }

    /**
     * Substraction between to tuples
     * /
    template <typename ... OtherTypes>
    Tuple<Types ...> operator-(const Tuple<OtherTypes...>& other) const {

    }

    /**
     * Substraction between to tuples - in place
     * /
    template <typename ... OtherTypes>
    Tuple<Types ...>& operator-=(const Tuple<OtherTypes...>& other) {

    }

    /**
     * Multiplication between to tuples
     * /
    template <typename ... OtherTypes>
    Tuple<Types ...> operator*(const Tuple<OtherTypes...>& other) const {

    }

    /**
     * Multiplication between to tuples - in place
     * /
    template <typename ... OtherTypes>
    Tuple<Types ...>& operator*=(const Tuple<OtherTypes...>& other) {

    }

    /**
     * Division between to tuples
     * /
    template <typename ... OtherTypes>
    Tuple<Types ...> operator/(const Tuple<OtherTypes...>& other) const {

    }

    /**
     * Division between to tuples - in place
     * /
    template <typename ... OtherTypes>
    Tuple<Types ...>& operator/=(const Tuple<OtherTypes...>& other) {

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
      return other.size == 0;
    }

    template <typename ... OtherTypes>
    bool operator<=(const Tuple<OtherTypes...>& other) const {
      return other.size == 0;
    }

    template <typename ... OtherTypes>
    bool operator>(const Tuple<OtherTypes...>& other) const {
      return other < this;
    }

    template <typename ... OtherTypes>
    bool operator>=(const Tuple<OtherTypes...>& other) const {
      return other.size == 0;
    }

    /**
     * Concatenate two tuples
     */
    template <typename ... OtherTypes>
    Tuple<Types ...> operator|(Tuple<OtherTypes...>&& other) {

    }
  };
  
  template<typename Type, typename ...Types>
  class Tuple<Type, Types ...> {
  private:
    size_t size;
    Type item;
    Tuple<Types...> next;
    
  public:
    /**
     * Constructor to initialize values
     */
    Tuple(Type head, Types ...queue): item (head), next (Tuple<Types...> (queue...)){
      size = sizeof... (queue) + 1;
      std::cerr << "Nbarg : " << size << "\n";
    }

    /**
     * Value getter
     */
    template<int index>
    const auto& get() const {
      if (index > 0){
        return next.template get<index-1> ();
      }
      if (index == 0){
        return item;
      }
      if (index < 0){
        return NULL;
      }
    }
    
    
    template<int index>
    constexpr auto& get() {
      if (index > 0){
        return next.template get<index-1> ();
      }
      if (index == 0){
        return item;
      }
      if (index < 0){
        return NULL;
      }
    }

    /**
     * Addition between to tuples
     * /
    template <typename ... OtherTypes>
    Tuple<Types ...> operator+(const Tuple<OtherTypes...>& other) const {

    }

    /**
     * Addition between to tuples - in place
     * /
    template <typename ... OtherTypes>
    Tuple<Types ...>& operator+=(const Tuple<OtherTypes...>& other) {

    }

    /**
     * Substraction between to tuples
     * /
    template <typename ... OtherTypes>
    Tuple<Types ...> operator-(const Tuple<OtherTypes...>& other) const {

    }

    /**
     * Substraction between to tuples - in place
     * /
    template <typename ... OtherTypes>
    Tuple<Types ...>& operator-=(const Tuple<OtherTypes...>& other) {

    }

    /**
     * Multiplication between to tuples
     * /
    template <typename ... OtherTypes>
    Tuple<Types ...> operator*(const Tuple<OtherTypes...>& other) const {

    }

    /**
     * Multiplication between to tuples - in place
     * /
    template <typename ... OtherTypes>
    Tuple<Types ...>& operator*=(const Tuple<OtherTypes...>& other) {

    }

    /**
     * Division between to tuples
     * /
    template <typename ... OtherTypes>
    Tuple<Types ...> operator/(const Tuple<OtherTypes...>& other) const {

    }

    /**
     * Division between to tuples - in place
     * /
    template <typename ... OtherTypes>
    Tuple<Types ...>& operator/=(const Tuple<OtherTypes...>& other) {

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
      return  !other.size == 0 && (item < other.item || (item == other.item && next < other.next));
    }

    template <typename ... OtherTypes>
    bool operator<=(const Tuple<OtherTypes...>& other) const {
      return !(other < this);
    }

    template <typename ... OtherTypes>
    bool operator>(const Tuple<OtherTypes...>& other) const {
      return other < this;
    }

    template <typename ... OtherTypes>
    bool operator>=(const Tuple<OtherTypes...>& other) const {
      return !(this < other);
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

  }
  
}
#endif // T_TUPLE_H
