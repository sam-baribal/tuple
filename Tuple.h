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
      * Addition between two tuples
      */
      template <typename ... OtherTypes>
      Tuple<Types ...> operator+(const Tuple<OtherTypes...>& other) const {
          Tuple<Types ...> res = *this;
          res += other;
          return res;
      }

      /**
      * Addition between two tuples - in place
      */
      template <typename ... OtherTypes>
      Tuple<Types ...>& operator+=(const Tuple<OtherTypes...>& other) {
          (void) (other.size == 0);
          return *this;
      }

      /**
      * Substraction between two tuples
      */
      template <typename ... OtherTypes>
      Tuple<Types ...> operator-(const Tuple<OtherTypes...>& other) const {
          Tuple<Types ...> res = *this;
          res -= other;
          return res;
      }

      /**
      * Substraction between two tuples - in place
      */
      template <typename ... OtherTypes>
      Tuple<Types ...>& operator-=(const Tuple<OtherTypes...>& other) {
          (void) (other.size == 0);
          return *this;
      }

      /**
      * Multiplication between two tuples
      */
      template <typename ... OtherTypes>
      Tuple<Types ...> operator*(const Tuple<OtherTypes...>& other) const {
          Tuple<Types ...> res = *this;
          res *= other;
          return res;
      }

      /**
      * Multiplication between two tuples - in place
      */
      template <typename ... OtherTypes>
      Tuple<Types ...>& operator*=(const Tuple<OtherTypes...>& other) {
          (void) (other.size == 0);
          return *this;
      }

      /**
      * Division between two tuples
      */
      template <typename ... OtherTypes>
      Tuple<Types ...> operator/(const Tuple<OtherTypes...>& other) const {
          Tuple<Types ...> res = *this;
          res /= other;
          return res;
      }

      /**
      * Division between two tuples - in place
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
   
      Tuple(): item(NULL), next (Tuple<Types ...>()){
        size = sizeof... (Types) + 1;
      }


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
      * Addition between two tuples
      */
      template <typename ... OtherTypes>
      Tuple<Type, Types ...> operator+(const Tuple<OtherTypes...>& other) const {
          Tuple<Type, Types ...> res = *this;
          res += other;
          return res;
      }

      /**
      * Addition between two tuples - in place
      */
      template <typename ... OtherTypes>
      Tuple<Type, Types ...>& operator+=(const Tuple<OtherTypes...>& other) {
          item += other.item;
          next += other.next;
          return *this;
      }

      /**
      * Substraction between two tuples
      */
      template <typename ... OtherTypes>
      Tuple<Type, Types ...> operator-(const Tuple<OtherTypes...>& other) const {
          Tuple<Type, Types ...> res = *this;
          res -= other;
          return res;
      }

      /**
      * Substraction between two tuples - in place
      */
      template <typename ... OtherTypes>
      Tuple<Type, Types ...>& operator-=(const Tuple<OtherTypes...>& other) {
          item -= other.item;
          next -= other.next;
          return *this;
      }

      /**
      * Multiplication between two tuples
      */
      template <typename ... OtherTypes>
      Tuple<Type, Types ...> operator*(const Tuple<OtherTypes...>& other) const {
          Tuple<Type, Types ...> res = *this;
          res *= other;
          return res;
      }

      /**
      * Multiplication between two tuples - in place
      */
      template <typename ... OtherTypes>
      Tuple<Type, Types ...>& operator*=(const Tuple<OtherTypes...>& other) {
          item *= other.item;
          next *= other.next;
          return *this;
      }

      /**
      * Division between two tuples
      */
      template <typename ... OtherTypes>
      Tuple<Type, Types ...> operator/(const Tuple<OtherTypes...>& other) const {
          Tuple<Type, Types ...> res = *this;
          res /= other;
          return res;
      }

      /**
      * Division between two tuples - in place
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
        //res.next = next_res; // <- res.next adress cannot change of type while not changing of value

        //return makeTuple (this, other); // <- return a Tuple<Tuple<Type, Types...>, Tuple<Othertypes...>>
        return res;
      }
      // Attempt to create a recursive function for concatenation
      /*template <typename CopyType, typename ... CopyTypes, typename ... OtherTypes>
      Tuple<CopyType, CopyTypes ..., OtherTypes ...> concatRec(Tuple<CopyType, CopyTypes ...>&& toCopy, Tuple<OtherTypes ...>&& other){
        Tuple <CopyType, CopyTypes ..., OtherTypes ...> res;
        res.item = toCopy.item;
        res.size = 1 + sizeof...(CopyTypes) + 1 + sizeof...(OtherTypes);
        if constexpr(sizeof...(CopyTypes) > 0){
          res.next = concatRec(toCopy.next, other);
        }
        if constexpr(sizeof...(CopyTypes) == 0){
          if constexpr(other != NULL){
            res.next = concatRec(other, NULL);
          }
        }
        return res;
      }*/

      Tuple<Type, Types...> operator|(Tuple<>&& other) {
        return *this;
      } 
  };

  template <>
  class Tuple<> {
    private:
      size_t size;
      void *item = NULL;
      void *next = NULL;
    public:
      template <typename ...U> friend class Tuple;
      /**
      * Default constructor
      */
      Tuple() {
          size = 0;
      }

      /**
      * Addition between two tuples
      */
      template <typename ... OtherTypes>
      Tuple<> operator+(const Tuple<OtherTypes...>& other) const {
          Tuple<> res = *this;
          res += other;
          return res;
      }

      /**
      * Addition between two tuples - in place
      */
      template <typename ... OtherTypes>
      Tuple<>& operator+=(const Tuple<OtherTypes...>& other) {
          (void) (other.size == 0);
          return *this;
      }

      /**
      * Substraction between two tuples
      */
      template <typename ... OtherTypes>
      Tuple<> operator-(const Tuple<OtherTypes...>& other) const {
          Tuple<> res = *this;
          res -= other;
          return res;
      }

      /**
      * Substraction between two tuples - in place
      */
      template <typename ... OtherTypes>
      Tuple<>& operator-=(const Tuple<OtherTypes...>& other) {
          (void) (other.size == 0);
          return *this;
      }

      /**
      * Multiplication between two tuples
      */
      template <typename ... OtherTypes>
      Tuple<> operator*(const Tuple<OtherTypes...>& other) const {
          Tuple<> res = *this;
          res *= other;
          return res;
      }

      /**
      * Multiplication between two tuples - in place
      */
      template <typename ... OtherTypes>
      Tuple<>& operator*=(const Tuple<OtherTypes...>& other) {
          (void) (other.size == 0);
          return *this;
      }

      /**
      * Division between two tuples
      */
      template <typename ... OtherTypes>
      Tuple<> operator/(const Tuple<OtherTypes...>& other) const {
          Tuple<> res = *this;
          res /= other;
          return res;
      }

      /**
      * Division between two tuples - in place
      */
      template <typename ... OtherTypes>
      Tuple<>& operator/=(const Tuple<OtherTypes...>& other) {
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

  /**
   * Helper function to create a tuple
   */
  template <class... Types>
  constexpr Tuple<Types...> makeTuple(Types&&... args) {
    return Tuple<Types...> (args ...);
  }
  
}
#endif // T_TUPLE_H
