#ifndef T_TUPLE_H
#define T_TUPLE_H

#include <typeinfo>
#include <sys/types.h>
#include <stdio.h>

namespace tpl {
  
  struct tuple_item {
    std::type_info type;
    void *item;
  };
  
  template<typename ...Types>
  class Tuple {
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
     * Constructor to initialize values
     */
    Tuple(Types... args) {
        size = sizeof... (args);
        std::cerr << "Nbarg : " << size << "\n";
    }

    /**
     * Value getter
     */
    template<int index>
    const auto& get() const {

    }

    template<int index>
    decltype (auto) get() {

    }

    /**
     * Addition between to tuples
     * /
    template <typename ... OtherTypes>
    Tuple</* implementation defined * />& operator+(const Tuple<OtherTypes...>& other) const {

    }

    /**
     * Addition between to tuples - in place
     * /
    template <typename ... OtherTypes>
    Tuple</* implementation defined * /> operator+=(const Tuple<OtherTypes...>& other) {

    }

    /**
     * Substraction between to tuples
     * /
    template <typename ... OtherTypes>
    Tuple</* implementation defined * /> operator-(const Tuple<OtherTypes...>& other) const {

    }

    /**
     * Substraction between to tuples - in place
     * /
    template <typename ... OtherTypes>
    Tuple</* implementation defined * />& operator-=(const Tuple<OtherTypes...>& other) {

    }

    /**
     * Multiplication between to tuples
     * /
    template <typename ... OtherTypes>
    Tuple</* implementation defined * /> operator*(const Tuple<OtherTypes...>& other) const {

    }

    /**
     * Multiplication between to tuples - in place
     * /
    template <typename ... OtherTypes>
    Tuple</* implementation defined * />& operator*=(const Tuple<OtherTypes...>& other) {

    }

    /**
     * Division between to tuples
     * /
    template <typename ... OtherTypes>
    Tuple</* implementation defined * /> operator/(const Tuple<OtherTypes...>& other) const {

    }

    /**
     * Division between to tuples - in place
     * /
    template <typename ... OtherTypes>
    Tuple</* implementation defined * />& operator/=(const Tuple<OtherTypes...>& other) {

    }

    /**
     * Comparaison operators
     * /
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
     * /
    template <typename ... OtherTypes>
    Tuple</* implementation defined * /> operator|(Tuple<OtherTypes...>&& other) {

    }
  };

  /**
   * Helper function to create a tuple
   * /
  template <class... Types>
  constexpr Tuple<Types...> makeTuple(Types&&... args) {

  }*/

};
}
#endif // T_TUPLE_H
