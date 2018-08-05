// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: single_sint32.proto

#include "single_sint32.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)

class Example1DefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<Example1>
      _instance;
} _Example1_default_instance_;
class Example2DefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<Example2>
      _instance;
} _Example2_default_instance_;
namespace protobuf_single_5fsint32_2eproto {
static void InitDefaultsExample1() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_Example1_default_instance_;
    new (ptr) ::Example1();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::Example1::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_Example1 =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsExample1}, {}};

static void InitDefaultsExample2() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_Example2_default_instance_;
    new (ptr) ::Example2();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::Example2::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_Example2 =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsExample2}, {}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_Example1.base);
  ::google::protobuf::internal::InitSCC(&scc_info_Example2.base);
}

::google::protobuf::Metadata file_level_metadata[2];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Example1, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Example1, sint32val_),
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Example2, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::Example2, sint32val_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::Example1)},
  { 6, -1, sizeof(::Example2)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::_Example1_default_instance_),
  reinterpret_cast<const ::google::protobuf::Message*>(&::_Example2_default_instance_),
};

static void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "single_sint32.proto", schemas, file_default_instances, TableStruct::offsets,
      file_level_metadata, NULL, NULL);
}

static void protobuf_AssignDescriptorsOnce() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 2);
}

static void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\023single_sint32.proto\"\035\n\010Example1\022\021\n\tsin"
      "t32Val\030\001 \001(\021\"\035\n\010Example2\022\021\n\tsint32Val\030\001 "
      "\003(\021b\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 91);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "single_sint32.proto", &protobuf_RegisterTypes);
}

void AddDescriptors() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_single_5fsint32_2eproto

// ===================================================================

void Example1::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Example1::kSint32ValFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Example1::Example1()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_single_5fsint32_2eproto::scc_info_Example1.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:Example1)
}
Example1::Example1(const Example1& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  sint32val_ = from.sint32val_;
  // @@protoc_insertion_point(copy_constructor:Example1)
}

void Example1::SharedCtor() {
  sint32val_ = 0;
}

Example1::~Example1() {
  // @@protoc_insertion_point(destructor:Example1)
  SharedDtor();
}

void Example1::SharedDtor() {
}

void Example1::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* Example1::descriptor() {
  ::protobuf_single_5fsint32_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_single_5fsint32_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const Example1& Example1::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_single_5fsint32_2eproto::scc_info_Example1.base);
  return *internal_default_instance();
}


void Example1::Clear() {
// @@protoc_insertion_point(message_clear_start:Example1)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  sint32val_ = 0;
  _internal_metadata_.Clear();
}

bool Example1::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:Example1)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // sint32 sint32Val = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_SINT32>(
                 input, &sint32val_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:Example1)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:Example1)
  return false;
#undef DO_
}

void Example1::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:Example1)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // sint32 sint32Val = 1;
  if (this->sint32val() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteSInt32(1, this->sint32val(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:Example1)
}

::google::protobuf::uint8* Example1::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:Example1)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // sint32 sint32Val = 1;
  if (this->sint32val() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteSInt32ToArray(1, this->sint32val(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Example1)
  return target;
}

size_t Example1::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Example1)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // sint32 sint32Val = 1;
  if (this->sint32val() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::SInt32Size(
        this->sint32val());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Example1::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:Example1)
  GOOGLE_DCHECK_NE(&from, this);
  const Example1* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const Example1>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:Example1)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:Example1)
    MergeFrom(*source);
  }
}

void Example1::MergeFrom(const Example1& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Example1)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.sint32val() != 0) {
    set_sint32val(from.sint32val());
  }
}

void Example1::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:Example1)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Example1::CopyFrom(const Example1& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Example1)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Example1::IsInitialized() const {
  return true;
}

void Example1::Swap(Example1* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Example1::InternalSwap(Example1* other) {
  using std::swap;
  swap(sint32val_, other->sint32val_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata Example1::GetMetadata() const {
  protobuf_single_5fsint32_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_single_5fsint32_2eproto::file_level_metadata[kIndexInFileMessages];
}


// ===================================================================

void Example2::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Example2::kSint32ValFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Example2::Example2()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_single_5fsint32_2eproto::scc_info_Example2.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:Example2)
}
Example2::Example2(const Example2& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      sint32val_(from.sint32val_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:Example2)
}

void Example2::SharedCtor() {
}

Example2::~Example2() {
  // @@protoc_insertion_point(destructor:Example2)
  SharedDtor();
}

void Example2::SharedDtor() {
}

void Example2::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* Example2::descriptor() {
  ::protobuf_single_5fsint32_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_single_5fsint32_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const Example2& Example2::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_single_5fsint32_2eproto::scc_info_Example2.base);
  return *internal_default_instance();
}


void Example2::Clear() {
// @@protoc_insertion_point(message_clear_start:Example2)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  sint32val_.Clear();
  _internal_metadata_.Clear();
}

bool Example2::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:Example2)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated sint32 sint32Val = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_SINT32>(
                 input, this->mutable_sint32val())));
        } else if (
            static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitiveNoInline<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_SINT32>(
                 1, 10u, input, this->mutable_sint32val())));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:Example2)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:Example2)
  return false;
#undef DO_
}

void Example2::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:Example2)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated sint32 sint32Val = 1;
  if (this->sint32val_size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteTag(1, ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
    output->WriteVarint32(static_cast< ::google::protobuf::uint32>(
        _sint32val_cached_byte_size_));
  }
  for (int i = 0, n = this->sint32val_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteSInt32NoTag(
      this->sint32val(i), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:Example2)
}

::google::protobuf::uint8* Example2::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:Example2)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated sint32 sint32Val = 1;
  if (this->sint32val_size() > 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(
      1,
      ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED,
      target);
    target = ::google::protobuf::io::CodedOutputStream::WriteVarint32ToArray(
        static_cast< ::google::protobuf::int32>(
            _sint32val_cached_byte_size_), target);
    target = ::google::protobuf::internal::WireFormatLite::
      WriteSInt32NoTagToArray(this->sint32val_, target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Example2)
  return target;
}

size_t Example2::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Example2)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // repeated sint32 sint32Val = 1;
  {
    size_t data_size = ::google::protobuf::internal::WireFormatLite::
      SInt32Size(this->sint32val_);
    if (data_size > 0) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
            static_cast< ::google::protobuf::int32>(data_size));
    }
    int cached_size = ::google::protobuf::internal::ToCachedSize(data_size);
    GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
    _sint32val_cached_byte_size_ = cached_size;
    GOOGLE_SAFE_CONCURRENT_WRITES_END();
    total_size += data_size;
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Example2::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:Example2)
  GOOGLE_DCHECK_NE(&from, this);
  const Example2* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const Example2>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:Example2)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:Example2)
    MergeFrom(*source);
  }
}

void Example2::MergeFrom(const Example2& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Example2)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  sint32val_.MergeFrom(from.sint32val_);
}

void Example2::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:Example2)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Example2::CopyFrom(const Example2& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Example2)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Example2::IsInitialized() const {
  return true;
}

void Example2::Swap(Example2* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Example2::InternalSwap(Example2* other) {
  using std::swap;
  sint32val_.InternalSwap(&other->sint32val_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata Example2::GetMetadata() const {
  protobuf_single_5fsint32_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_single_5fsint32_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::Example1* Arena::CreateMaybeMessage< ::Example1 >(Arena* arena) {
  return Arena::CreateInternal< ::Example1 >(arena);
}
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::Example2* Arena::CreateMaybeMessage< ::Example2 >(Arena* arena) {
  return Arena::CreateInternal< ::Example2 >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)