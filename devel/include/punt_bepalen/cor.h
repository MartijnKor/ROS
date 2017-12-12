// Generated by gencpp from file punt_bepalen/cor.msg
// DO NOT EDIT!


#ifndef PUNT_BEPALEN_MESSAGE_COR_H
#define PUNT_BEPALEN_MESSAGE_COR_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace punt_bepalen
{
template <class ContainerAllocator>
struct cor_
{
  typedef cor_<ContainerAllocator> Type;

  cor_()
    : x(0)
    , y(0)  {
    }
  cor_(const ContainerAllocator& _alloc)
    : x(0)
    , y(0)  {
  (void)_alloc;
    }



   typedef int32_t _x_type;
  _x_type x;

   typedef int32_t _y_type;
  _y_type y;




  typedef boost::shared_ptr< ::punt_bepalen::cor_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::punt_bepalen::cor_<ContainerAllocator> const> ConstPtr;

}; // struct cor_

typedef ::punt_bepalen::cor_<std::allocator<void> > cor;

typedef boost::shared_ptr< ::punt_bepalen::cor > corPtr;
typedef boost::shared_ptr< ::punt_bepalen::cor const> corConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::punt_bepalen::cor_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::punt_bepalen::cor_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace punt_bepalen

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'punt_bepalen': ['/home/daan/ros/src/punt_bepalen/msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::punt_bepalen::cor_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::punt_bepalen::cor_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::punt_bepalen::cor_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::punt_bepalen::cor_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::punt_bepalen::cor_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::punt_bepalen::cor_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::punt_bepalen::cor_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bd7b43fd41d4c47bf5c703cc7d016709";
  }

  static const char* value(const ::punt_bepalen::cor_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xbd7b43fd41d4c47bULL;
  static const uint64_t static_value2 = 0xf5c703cc7d016709ULL;
};

template<class ContainerAllocator>
struct DataType< ::punt_bepalen::cor_<ContainerAllocator> >
{
  static const char* value()
  {
    return "punt_bepalen/cor";
  }

  static const char* value(const ::punt_bepalen::cor_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::punt_bepalen::cor_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32 x\n\
int32 y\n\
";
  }

  static const char* value(const ::punt_bepalen::cor_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::punt_bepalen::cor_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.x);
      stream.next(m.y);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct cor_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::punt_bepalen::cor_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::punt_bepalen::cor_<ContainerAllocator>& v)
  {
    s << indent << "x: ";
    Printer<int32_t>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<int32_t>::stream(s, indent + "  ", v.y);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PUNT_BEPALEN_MESSAGE_COR_H