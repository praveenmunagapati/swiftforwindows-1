//===--- ReferencedNameTracker.h - Records looked-up names ------*- C++ -*-===//
//
// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2016 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See http://swift.org/LICENSE.txt for license information
// See http://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//
//===----------------------------------------------------------------------===//

#ifndef SWIFT_REFERENCEDNAMETRACKER_H
#define SWIFT_REFERENCEDNAMETRACKER_H

#include "swift/AST/Identifier.h"
#include "llvm/ADT/DenseMap.h"

namespace swift {

class NominalTypeDecl;

class ReferencedNameTracker {
#define TRACKED_SET(KIND, NAME) \
private: \
  llvm::DenseMap<KIND, bool> NAME##s; \
public: \
  void add##NAME(KIND new##NAME, bool isCascadingUse) { \
    NAME##s[new##NAME] |= isCascadingUse; \
  } \
  const decltype(NAME##s) &get##NAME##s() const { \
    return NAME##s; \
  }

  TRACKED_SET(Identifier, TopLevelName)
  TRACKED_SET(Identifier, DynamicLookupName)

  using MemberPair = std::pair<const NominalTypeDecl *, Identifier>;
  TRACKED_SET(MemberPair, UsedMember)

#undef TRACKED_SET
};

} // end namespace swift

#endif // LLVM_SWIFT_REFERENCEDNAMETRACKER_H
