// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from chapt4_interfaces:srv/Partol.idl
// generated code does not contain a copyright notice
#include "chapt4_interfaces/srv/detail/partol__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "chapt4_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "chapt4_interfaces/srv/detail/partol__struct.h"
#include "chapt4_interfaces/srv/detail/partol__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _Partol_Request__ros_msg_type = chapt4_interfaces__srv__Partol_Request;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_chapt4_interfaces
bool cdr_serialize_chapt4_interfaces__srv__Partol_Request(
  const chapt4_interfaces__srv__Partol_Request * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: target_x
  {
    cdr << ros_message->target_x;
  }

  // Field name: target_y
  {
    cdr << ros_message->target_y;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_chapt4_interfaces
bool cdr_deserialize_chapt4_interfaces__srv__Partol_Request(
  eprosima::fastcdr::Cdr & cdr,
  chapt4_interfaces__srv__Partol_Request * ros_message)
{
  // Field name: target_x
  {
    cdr >> ros_message->target_x;
  }

  // Field name: target_y
  {
    cdr >> ros_message->target_y;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_chapt4_interfaces
size_t get_serialized_size_chapt4_interfaces__srv__Partol_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Partol_Request__ros_msg_type * ros_message = static_cast<const _Partol_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: target_x
  {
    size_t item_size = sizeof(ros_message->target_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: target_y
  {
    size_t item_size = sizeof(ros_message->target_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_chapt4_interfaces
size_t max_serialized_size_chapt4_interfaces__srv__Partol_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: target_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: target_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = chapt4_interfaces__srv__Partol_Request;
    is_plain =
      (
      offsetof(DataType, target_y) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_chapt4_interfaces
bool cdr_serialize_key_chapt4_interfaces__srv__Partol_Request(
  const chapt4_interfaces__srv__Partol_Request * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: target_x
  {
    cdr << ros_message->target_x;
  }

  // Field name: target_y
  {
    cdr << ros_message->target_y;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_chapt4_interfaces
size_t get_serialized_size_key_chapt4_interfaces__srv__Partol_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Partol_Request__ros_msg_type * ros_message = static_cast<const _Partol_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: target_x
  {
    size_t item_size = sizeof(ros_message->target_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: target_y
  {
    size_t item_size = sizeof(ros_message->target_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_chapt4_interfaces
size_t max_serialized_size_key_chapt4_interfaces__srv__Partol_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: target_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: target_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = chapt4_interfaces__srv__Partol_Request;
    is_plain =
      (
      offsetof(DataType, target_y) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _Partol_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const chapt4_interfaces__srv__Partol_Request * ros_message = static_cast<const chapt4_interfaces__srv__Partol_Request *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_chapt4_interfaces__srv__Partol_Request(ros_message, cdr);
}

static bool _Partol_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  chapt4_interfaces__srv__Partol_Request * ros_message = static_cast<chapt4_interfaces__srv__Partol_Request *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_chapt4_interfaces__srv__Partol_Request(cdr, ros_message);
}

static uint32_t _Partol_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_chapt4_interfaces__srv__Partol_Request(
      untyped_ros_message, 0));
}

static size_t _Partol_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_chapt4_interfaces__srv__Partol_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Partol_Request = {
  "chapt4_interfaces::srv",
  "Partol_Request",
  _Partol_Request__cdr_serialize,
  _Partol_Request__cdr_deserialize,
  _Partol_Request__get_serialized_size,
  _Partol_Request__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _Partol_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Partol_Request,
  get_message_typesupport_handle_function,
  &chapt4_interfaces__srv__Partol_Request__get_type_hash,
  &chapt4_interfaces__srv__Partol_Request__get_type_description,
  &chapt4_interfaces__srv__Partol_Request__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, chapt4_interfaces, srv, Partol_Request)() {
  return &_Partol_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <cstddef>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "chapt4_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "chapt4_interfaces/srv/detail/partol__struct.h"
// already included above
// #include "chapt4_interfaces/srv/detail/partol__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _Partol_Response__ros_msg_type = chapt4_interfaces__srv__Partol_Response;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_chapt4_interfaces
bool cdr_serialize_chapt4_interfaces__srv__Partol_Response(
  const chapt4_interfaces__srv__Partol_Response * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: result
  {
    cdr << ros_message->result;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_chapt4_interfaces
bool cdr_deserialize_chapt4_interfaces__srv__Partol_Response(
  eprosima::fastcdr::Cdr & cdr,
  chapt4_interfaces__srv__Partol_Response * ros_message)
{
  // Field name: result
  {
    cdr >> ros_message->result;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_chapt4_interfaces
size_t get_serialized_size_chapt4_interfaces__srv__Partol_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Partol_Response__ros_msg_type * ros_message = static_cast<const _Partol_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: result
  {
    size_t item_size = sizeof(ros_message->result);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_chapt4_interfaces
size_t max_serialized_size_chapt4_interfaces__srv__Partol_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: result
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = chapt4_interfaces__srv__Partol_Response;
    is_plain =
      (
      offsetof(DataType, result) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_chapt4_interfaces
bool cdr_serialize_key_chapt4_interfaces__srv__Partol_Response(
  const chapt4_interfaces__srv__Partol_Response * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: result
  {
    cdr << ros_message->result;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_chapt4_interfaces
size_t get_serialized_size_key_chapt4_interfaces__srv__Partol_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Partol_Response__ros_msg_type * ros_message = static_cast<const _Partol_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: result
  {
    size_t item_size = sizeof(ros_message->result);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_chapt4_interfaces
size_t max_serialized_size_key_chapt4_interfaces__srv__Partol_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: result
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = chapt4_interfaces__srv__Partol_Response;
    is_plain =
      (
      offsetof(DataType, result) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _Partol_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const chapt4_interfaces__srv__Partol_Response * ros_message = static_cast<const chapt4_interfaces__srv__Partol_Response *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_chapt4_interfaces__srv__Partol_Response(ros_message, cdr);
}

static bool _Partol_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  chapt4_interfaces__srv__Partol_Response * ros_message = static_cast<chapt4_interfaces__srv__Partol_Response *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_chapt4_interfaces__srv__Partol_Response(cdr, ros_message);
}

static uint32_t _Partol_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_chapt4_interfaces__srv__Partol_Response(
      untyped_ros_message, 0));
}

static size_t _Partol_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_chapt4_interfaces__srv__Partol_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Partol_Response = {
  "chapt4_interfaces::srv",
  "Partol_Response",
  _Partol_Response__cdr_serialize,
  _Partol_Response__cdr_deserialize,
  _Partol_Response__get_serialized_size,
  _Partol_Response__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _Partol_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Partol_Response,
  get_message_typesupport_handle_function,
  &chapt4_interfaces__srv__Partol_Response__get_type_hash,
  &chapt4_interfaces__srv__Partol_Response__get_type_description,
  &chapt4_interfaces__srv__Partol_Response__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, chapt4_interfaces, srv, Partol_Response)() {
  return &_Partol_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <cstddef>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "chapt4_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "chapt4_interfaces/srv/detail/partol__struct.h"
// already included above
// #include "chapt4_interfaces/srv/detail/partol__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "service_msgs/msg/detail/service_event_info__functions.h"  // info

// forward declare type support functions

bool cdr_serialize_chapt4_interfaces__srv__Partol_Request(
  const chapt4_interfaces__srv__Partol_Request * ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool cdr_deserialize_chapt4_interfaces__srv__Partol_Request(
  eprosima::fastcdr::Cdr & cdr,
  chapt4_interfaces__srv__Partol_Request * ros_message);

size_t get_serialized_size_chapt4_interfaces__srv__Partol_Request(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_chapt4_interfaces__srv__Partol_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool cdr_serialize_key_chapt4_interfaces__srv__Partol_Request(
  const chapt4_interfaces__srv__Partol_Request * ros_message,
  eprosima::fastcdr::Cdr & cdr);

size_t get_serialized_size_key_chapt4_interfaces__srv__Partol_Request(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_key_chapt4_interfaces__srv__Partol_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, chapt4_interfaces, srv, Partol_Request)();

bool cdr_serialize_chapt4_interfaces__srv__Partol_Response(
  const chapt4_interfaces__srv__Partol_Response * ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool cdr_deserialize_chapt4_interfaces__srv__Partol_Response(
  eprosima::fastcdr::Cdr & cdr,
  chapt4_interfaces__srv__Partol_Response * ros_message);

size_t get_serialized_size_chapt4_interfaces__srv__Partol_Response(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_chapt4_interfaces__srv__Partol_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool cdr_serialize_key_chapt4_interfaces__srv__Partol_Response(
  const chapt4_interfaces__srv__Partol_Response * ros_message,
  eprosima::fastcdr::Cdr & cdr);

size_t get_serialized_size_key_chapt4_interfaces__srv__Partol_Response(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_key_chapt4_interfaces__srv__Partol_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, chapt4_interfaces, srv, Partol_Response)();

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_chapt4_interfaces
bool cdr_serialize_service_msgs__msg__ServiceEventInfo(
  const service_msgs__msg__ServiceEventInfo * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_chapt4_interfaces
bool cdr_deserialize_service_msgs__msg__ServiceEventInfo(
  eprosima::fastcdr::Cdr & cdr,
  service_msgs__msg__ServiceEventInfo * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_chapt4_interfaces
size_t get_serialized_size_service_msgs__msg__ServiceEventInfo(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_chapt4_interfaces
size_t max_serialized_size_service_msgs__msg__ServiceEventInfo(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_chapt4_interfaces
bool cdr_serialize_key_service_msgs__msg__ServiceEventInfo(
  const service_msgs__msg__ServiceEventInfo * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_chapt4_interfaces
size_t get_serialized_size_key_service_msgs__msg__ServiceEventInfo(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_chapt4_interfaces
size_t max_serialized_size_key_service_msgs__msg__ServiceEventInfo(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_chapt4_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, service_msgs, msg, ServiceEventInfo)();


using _Partol_Event__ros_msg_type = chapt4_interfaces__srv__Partol_Event;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_chapt4_interfaces
bool cdr_serialize_chapt4_interfaces__srv__Partol_Event(
  const chapt4_interfaces__srv__Partol_Event * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: info
  {
    cdr_serialize_service_msgs__msg__ServiceEventInfo(
      &ros_message->info, cdr);
  }

  // Field name: request
  {
    size_t size = ros_message->request.size;
    auto array_ptr = ros_message->request.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_chapt4_interfaces__srv__Partol_Request(
        &array_ptr[i], cdr);
    }
  }

  // Field name: response
  {
    size_t size = ros_message->response.size;
    auto array_ptr = ros_message->response.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_chapt4_interfaces__srv__Partol_Response(
        &array_ptr[i], cdr);
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_chapt4_interfaces
bool cdr_deserialize_chapt4_interfaces__srv__Partol_Event(
  eprosima::fastcdr::Cdr & cdr,
  chapt4_interfaces__srv__Partol_Event * ros_message)
{
  // Field name: info
  {
    cdr_deserialize_service_msgs__msg__ServiceEventInfo(cdr, &ros_message->info);
  }

  // Field name: request
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.get_state();
    bool correct_size = cdr.jump(size);
    cdr.set_state(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    if (ros_message->request.data) {
      chapt4_interfaces__srv__Partol_Request__Sequence__fini(&ros_message->request);
    }
    if (!chapt4_interfaces__srv__Partol_Request__Sequence__init(&ros_message->request, size)) {
      fprintf(stderr, "failed to create array for field 'request'");
      return false;
    }
    auto array_ptr = ros_message->request.data;
    for (size_t i = 0; i < size; ++i) {
      cdr_deserialize_chapt4_interfaces__srv__Partol_Request(cdr, &array_ptr[i]);
    }
  }

  // Field name: response
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.get_state();
    bool correct_size = cdr.jump(size);
    cdr.set_state(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    if (ros_message->response.data) {
      chapt4_interfaces__srv__Partol_Response__Sequence__fini(&ros_message->response);
    }
    if (!chapt4_interfaces__srv__Partol_Response__Sequence__init(&ros_message->response, size)) {
      fprintf(stderr, "failed to create array for field 'response'");
      return false;
    }
    auto array_ptr = ros_message->response.data;
    for (size_t i = 0; i < size; ++i) {
      cdr_deserialize_chapt4_interfaces__srv__Partol_Response(cdr, &array_ptr[i]);
    }
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_chapt4_interfaces
size_t get_serialized_size_chapt4_interfaces__srv__Partol_Event(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Partol_Event__ros_msg_type * ros_message = static_cast<const _Partol_Event__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: info
  current_alignment += get_serialized_size_service_msgs__msg__ServiceEventInfo(
    &(ros_message->info), current_alignment);

  // Field name: request
  {
    size_t array_size = ros_message->request.size;
    auto array_ptr = ros_message->request.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_chapt4_interfaces__srv__Partol_Request(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: response
  {
    size_t array_size = ros_message->response.size;
    auto array_ptr = ros_message->response.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_chapt4_interfaces__srv__Partol_Response(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_chapt4_interfaces
size_t max_serialized_size_chapt4_interfaces__srv__Partol_Event(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: info
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_service_msgs__msg__ServiceEventInfo(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: request
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_chapt4_interfaces__srv__Partol_Request(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: response
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_chapt4_interfaces__srv__Partol_Response(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = chapt4_interfaces__srv__Partol_Event;
    is_plain =
      (
      offsetof(DataType, response) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_chapt4_interfaces
bool cdr_serialize_key_chapt4_interfaces__srv__Partol_Event(
  const chapt4_interfaces__srv__Partol_Event * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: info
  {
    cdr_serialize_key_service_msgs__msg__ServiceEventInfo(
      &ros_message->info, cdr);
  }

  // Field name: request
  {
    size_t size = ros_message->request.size;
    auto array_ptr = ros_message->request.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_key_chapt4_interfaces__srv__Partol_Request(
        &array_ptr[i], cdr);
    }
  }

  // Field name: response
  {
    size_t size = ros_message->response.size;
    auto array_ptr = ros_message->response.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_key_chapt4_interfaces__srv__Partol_Response(
        &array_ptr[i], cdr);
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_chapt4_interfaces
size_t get_serialized_size_key_chapt4_interfaces__srv__Partol_Event(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Partol_Event__ros_msg_type * ros_message = static_cast<const _Partol_Event__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: info
  current_alignment += get_serialized_size_key_service_msgs__msg__ServiceEventInfo(
    &(ros_message->info), current_alignment);

  // Field name: request
  {
    size_t array_size = ros_message->request.size;
    auto array_ptr = ros_message->request.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_key_chapt4_interfaces__srv__Partol_Request(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: response
  {
    size_t array_size = ros_message->response.size;
    auto array_ptr = ros_message->response.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_key_chapt4_interfaces__srv__Partol_Response(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_chapt4_interfaces
size_t max_serialized_size_key_chapt4_interfaces__srv__Partol_Event(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: info
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_service_msgs__msg__ServiceEventInfo(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: request
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_chapt4_interfaces__srv__Partol_Request(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: response
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_chapt4_interfaces__srv__Partol_Response(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = chapt4_interfaces__srv__Partol_Event;
    is_plain =
      (
      offsetof(DataType, response) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _Partol_Event__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const chapt4_interfaces__srv__Partol_Event * ros_message = static_cast<const chapt4_interfaces__srv__Partol_Event *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_chapt4_interfaces__srv__Partol_Event(ros_message, cdr);
}

static bool _Partol_Event__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  chapt4_interfaces__srv__Partol_Event * ros_message = static_cast<chapt4_interfaces__srv__Partol_Event *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_chapt4_interfaces__srv__Partol_Event(cdr, ros_message);
}

static uint32_t _Partol_Event__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_chapt4_interfaces__srv__Partol_Event(
      untyped_ros_message, 0));
}

static size_t _Partol_Event__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_chapt4_interfaces__srv__Partol_Event(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Partol_Event = {
  "chapt4_interfaces::srv",
  "Partol_Event",
  _Partol_Event__cdr_serialize,
  _Partol_Event__cdr_deserialize,
  _Partol_Event__get_serialized_size,
  _Partol_Event__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _Partol_Event__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Partol_Event,
  get_message_typesupport_handle_function,
  &chapt4_interfaces__srv__Partol_Event__get_type_hash,
  &chapt4_interfaces__srv__Partol_Event__get_type_description,
  &chapt4_interfaces__srv__Partol_Event__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, chapt4_interfaces, srv, Partol_Event)() {
  return &_Partol_Event__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "chapt4_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "chapt4_interfaces/srv/partol.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t Partol__callbacks = {
  "chapt4_interfaces::srv",
  "Partol",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, chapt4_interfaces, srv, Partol_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, chapt4_interfaces, srv, Partol_Response)(),
};

static rosidl_service_type_support_t Partol__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &Partol__callbacks,
  get_service_typesupport_handle_function,
  &_Partol_Request__type_support,
  &_Partol_Response__type_support,
  &_Partol_Event__type_support,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    chapt4_interfaces,
    srv,
    Partol
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    chapt4_interfaces,
    srv,
    Partol
  ),
  &chapt4_interfaces__srv__Partol__get_type_hash,
  &chapt4_interfaces__srv__Partol__get_type_description,
  &chapt4_interfaces__srv__Partol__get_type_description_sources,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, chapt4_interfaces, srv, Partol)() {
  return &Partol__handle;
}

#if defined(__cplusplus)
}
#endif
