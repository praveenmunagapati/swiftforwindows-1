// RUN: %target-run-simple-swift | FileCheck %s
// REQUIRES: executable_test

func test(_ s: String)
{
  print(s)
  var s2 = s[s.startIndex.advanced(by: 2)..<s.startIndex.advanced(by: 4)]
  print(s2)
  var s3 = s2[s2.startIndex..<s2.startIndex]
  var s4 = s3[s2.startIndex..<s2.startIndex]
}

test("some text")

// CHECK: some text
// CHECK: me
