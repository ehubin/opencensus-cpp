// Copyright 2017, OpenCensus Authors
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "opencensus/stats/measure_registry.h"

#include "absl/strings/str_cat.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "opencensus/stats/measure.h"
#include "opencensus/stats/measure_descriptor.h"

namespace opencensus {
namespace stats {
namespace {

// Generates unique measure names. Since the registry does not support
// unregistering, all measure names must be different across test cases.
std::string MakeUniqueName() {
  static int counter;
  return absl::StrCat("name", counter++);
}

TEST(MeasureRegistryTest, RegisterDouble) {
  const std::string name = MakeUniqueName();
  const std::string units = "units";
  const std::string description = "description";

  MeasureDouble measure =
      MeasureRegistry::RegisterDouble(name, units, description);
  ASSERT_TRUE(measure.IsValid());
  const MeasureDescriptor& descriptor = measure.GetDescriptor();
  EXPECT_EQ(name, descriptor.name());
  EXPECT_EQ(units, descriptor.units());
  EXPECT_EQ(description, descriptor.description());
  EXPECT_EQ(MeasureDescriptor::Type::kDouble, descriptor.type());
}

TEST(MeasureRegistryTest, RegisterInt) {
  const std::string name = MakeUniqueName();
  const std::string units = "units";
  const std::string description = "description";

  MeasureInt measure = MeasureRegistry::RegisterInt(name, units, description);
  ASSERT_TRUE(measure.IsValid());
  const MeasureDescriptor& descriptor = measure.GetDescriptor();
  EXPECT_EQ(name, descriptor.name());
  EXPECT_EQ(units, descriptor.units());
  EXPECT_EQ(description, descriptor.description());
  EXPECT_EQ(MeasureDescriptor::Type::kInt64, descriptor.type());
}

TEST(MeasureRegistryTest, RegisteringEmptyNameFails) {
  EXPECT_FALSE(MeasureRegistry::RegisterDouble("", "", "").IsValid());
}

TEST(MeasureRegistryTest, DuplicateRegistrationsFail) {
  const std::string name = MakeUniqueName();
  const std::string units = "units";

  MeasureDouble measure = MeasureRegistry::RegisterDouble(name, units, "");
  ASSERT_TRUE(measure.IsValid());

  // Subsequent registrations should fail, regardless of type.
  EXPECT_FALSE(MeasureRegistry::RegisterDouble(name, "", "").IsValid());
  EXPECT_FALSE(MeasureRegistry::RegisterInt(name, "", "").IsValid());

  // The descriptor should not have been updated.
  EXPECT_EQ(units, measure.GetDescriptor().units());
}

TEST(MeasureRegistryTest, GetDescriptorByName) {
  const std::string name = MakeUniqueName();
  const std::string units = "units";
  const std::string description = "description";

  MeasureDouble measure =
      MeasureRegistry::RegisterDouble(name, units, description);
  ASSERT_TRUE(measure.IsValid());
  EXPECT_EQ(measure.GetDescriptor(),
            MeasureRegistry::GetDescriptorByName(name));
}

TEST(MeasureRegistryTest, GetDescriptorByNameWithUnregisteredName) {
  const MeasureDescriptor& descriptor =
      MeasureRegistry::GetDescriptorByName(MakeUniqueName());
  EXPECT_TRUE(descriptor.name().empty());
  EXPECT_TRUE(descriptor.units().empty());
  EXPECT_TRUE(descriptor.description().empty());
}

TEST(MeasureRegistryTest, GetMeasureDoubleByName) {
  const std::string name = MakeUniqueName();
  MeasureDouble measure1 = MeasureRegistry::RegisterDouble(name, "", "");
  ASSERT_TRUE(measure1.IsValid());

  MeasureDouble measure2 = MeasureRegistry::GetMeasureDoubleByName(name);
  ASSERT_TRUE(measure2.IsValid());
  EXPECT_EQ(measure1, measure2);
  EXPECT_EQ(measure1.GetDescriptor(), measure2.GetDescriptor());
}

TEST(MeasureRegistryTest, GetMeasureIntByName) {
  const std::string name = MakeUniqueName();
  MeasureInt measure1 = MeasureRegistry::RegisterInt(name, "", "");
  ASSERT_TRUE(measure1.IsValid());

  MeasureInt measure2 = MeasureRegistry::GetMeasureIntByName(name);
  ASSERT_TRUE(measure2.IsValid());
  EXPECT_EQ(measure1, measure2);
  EXPECT_EQ(measure1.GetDescriptor(), measure2.GetDescriptor());
}

TEST(MeasureRegistryTest, GetMeasureDoubleUnregisteredFails) {
  EXPECT_FALSE(
      MeasureRegistry::GetMeasureDoubleByName(MakeUniqueName()).IsValid());
}

TEST(MeasureRegistryTest, GetMeasureIntUnregisteredFails) {
  EXPECT_FALSE(
      MeasureRegistry::GetMeasureIntByName(MakeUniqueName()).IsValid());
}

TEST(MeasureRegistryTest, GetMeasureByNameWithWrongTypeFails) {
  const std::string double_name = MakeUniqueName();
  const std::string int_name = MakeUniqueName();
  MeasureDouble measure_double =
      MeasureRegistry::RegisterDouble(double_name, "", "");
  MeasureInt measure_int = MeasureRegistry::RegisterInt(int_name, "", "");

  MeasureInt measure_double_mistyped =
      MeasureRegistry::GetMeasureIntByName(double_name);
  EXPECT_FALSE(measure_double_mistyped.IsValid());
  EXPECT_NE(measure_double.GetDescriptor(),
            measure_double_mistyped.GetDescriptor());

  MeasureDouble measure_int_mistyped =
      MeasureRegistry::GetMeasureDoubleByName(int_name);
  EXPECT_FALSE(measure_int_mistyped.IsValid());
  EXPECT_NE(measure_int.GetDescriptor(), measure_int_mistyped.GetDescriptor());
}

}  // namespace
}  // namespace stats
}  // namespace opencensus
