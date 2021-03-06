#include "gtest/gtest.h"

#include "BMS/Filename.hpp"

#include <iostream>
#include <string>

class FilenameComplete : public ::testing::Test {
protected:
  bms::Filename filename;
  std::string fullpath;
  std::string path;
  std::string base;
  std::string ext;

  FilenameComplete() {
    path = "/path/to/somewhere";
    base = "base";
    ext = "ext";
    fullpath = path + "/" + base + "." + ext;
    filename = bms::Filename(fullpath);
  }
};

TEST_F(FilenameComplete, FullpathCorrect) {
  EXPECT_TRUE(filename.fullpath() == fullpath);
}

TEST_F(FilenameComplete, FullpathWrong) {
  EXPECT_FALSE(filename.fullpath() == std::string("random string"));
}

TEST_F(FilenameComplete, PathCorrect) {
  EXPECT_TRUE(filename.getPath() == path);
}

TEST_F(FilenameComplete, PathWrong) {
  EXPECT_FALSE(filename.getPath() == std::string("random string"));
}

TEST_F(FilenameComplete, BaseCorrect) {
  EXPECT_TRUE(filename.getBase() == base);
}

TEST_F(FilenameComplete, BaseWrong) {
  EXPECT_FALSE(filename.getBase() == std::string("random string"));
}

TEST_F(FilenameComplete, ExtCorrect) {
  EXPECT_TRUE(filename.getExt() == ext);
}

TEST_F(FilenameComplete, ExtWrong) {
  EXPECT_FALSE(filename.getExt() == std::string("random string"));
}
