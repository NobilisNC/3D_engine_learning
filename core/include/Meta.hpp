#ifndef META_HPP
#define META_HPP

namespace soap {

template <typename R, typename ... Types>
constexpr std::integral_constant<unsigned, sizeof ...(Types)> getArgumentCount( R(*f)(Types ...))
{
   return std::integral_constant<unsigned, sizeof ...(Types)>{};
}


}

#endif
