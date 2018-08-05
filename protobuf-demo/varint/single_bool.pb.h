// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: single_bool.proto

#ifndef PROTOBUF_INCLUDED_single_5fbool_2eproto
#define PROTOBUF_INCLUDED_single_5fbool_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_single_5fbool_2eproto 

namespace protobuf_single_5fbool_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[1];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_single_5fbool_2eproto
class Example1;
class Example1DefaultTypeInternal;
extern Example1DefaultTypeInternal _Example1_default_instance_;
namespace google {
namespace protobuf {
template<> ::Example1* Arena::CreateMaybeMessage<::Example1>(Arena*);
}  // namespace protobuf
}  // namespace google

// ===================================================================

class Example1 : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Example1) */ {
 public:
  Example1();
  virtual ~Example1();

  Example1(const Example1& from);

  inline Example1& operator=(const Example1& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Example1(Example1&& from) noexcept
    : Example1() {
    *this = ::std::move(from);
  }

  inline Example1& operator=(Example1&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Example1& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Example1* internal_default_instance() {
    return reinterpret_cast<const Example1*>(
               &_Example1_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(Example1* other);
  friend void swap(Example1& a, Example1& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Example1* New() const final {
    return CreateMaybeMessage<Example1>(NULL);
  }

  Example1* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Example1>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Example1& from);
  void MergeFrom(const Example1& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Example1* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // bool boolVal = 1;
  void clear_boolval();
  static const int kBoolValFieldNumber = 1;
  bool boolval() const;
  void set_boolval(bool value);

  // @@protoc_insertion_point(class_scope:Example1)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool boolval_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_single_5fbool_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Example1

// bool boolVal = 1;
inline void Example1::clear_boolval() {
  boolval_ = false;
}
inline bool Example1::boolval() const {
  // @@protoc_insertion_point(field_get:Example1.boolVal)
  return boolval_;
}
inline void Example1::set_boolval(bool value) {
  
  boolval_ = value;
  // @@protoc_insertion_point(field_set:Example1.boolVal)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_single_5fbool_2eproto
