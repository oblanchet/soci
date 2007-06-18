#ifndef EXCHANGE_TRAITS_H_INCLUDED
#define EXCHANGE_TRAITS_H_INCLUDED

#include <vector>
#include <boost/optional.hpp>

namespace soci
{

namespace details
{

struct basic_type_tag {};
struct user_type_tag {};

template <typename T>
struct exchange_traits
{
    // this is used for tag-dispatch between implementations for basic types
    // and user-defined types
    typedef user_type_tag type_family;
};

template <>
struct exchange_traits<short>
{
    typedef basic_type_tag type_family;    
    enum { eXType = eXShort };
};

template <>
struct exchange_traits<int>
{
    typedef basic_type_tag type_family;    
    enum { eXType = eXInteger };
};

template <>
struct exchange_traits<char>
{
    typedef basic_type_tag type_family;    
    enum { eXType = eXChar };
};

template <>
struct exchange_traits<unsigned long>
{
    typedef basic_type_tag type_family;    
    enum { eXType = eXUnsignedLong };
};

template <>
struct exchange_traits<double>
{
    typedef basic_type_tag type_family;    
    enum { eXType = eXDouble };
};

template <>
struct exchange_traits<char *>
{
    typedef basic_type_tag type_family;
};

template <std::size_t N>
struct exchange_traits<char[N]>
{
    typedef basic_type_tag type_family;
};

template <>
struct exchange_traits<std::string>
{
    typedef basic_type_tag type_family;    
    enum { eXType = eXStdString };
};

template <>
struct exchange_traits<std::tm>
{
    typedef basic_type_tag type_family;    
    enum { eXType = eXStdTm };
};

// for complete tag dispatch

template <typename T>
struct exchange_traits<std::vector<T> >
{
    typedef typename exchange_traits<T>::type_family type_family;
    enum { eXType = exchange_traits<T>::eXType };
};

template <typename T>
struct exchange_traits<boost::optional<T> >
{
    typedef typename exchange_traits<T>::type_family type_family;
    enum { eXType = exchange_traits<T>::eXType };
};

// Note: traits for std::vector<boost::optional<T> > not needed,
// they are composed automatically out of the two above

} // namespace details
} // namespace soci

#endif // EXCHANGE_TRAITS_H_INCLUDED
