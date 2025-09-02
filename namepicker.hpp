#ifndef _NAMEPICKER_
#define _NAMEPICKER_

#include "history.hpp"
#include <cstddef>
#include <string>
#include <vector>

class NamePicker {
public:
  NamePicker();
  const std::string &pick() const;
  std::string pick_no_recent();

private:
  int rdm(std::vector<std::string>::size_type sz) const;
  History hstry;
  std::string filename_history = "history.txt";
  std::vector<std::string> st, lst{
                                 "石珍丹",
                                 "顾淑楠",
                                 "王子欣",
                                 "胡友成",
                                 "晏佳男",
                                 "刘静岩",
                                 "郑丽莉",
                                 "吴自成",
                                 "谢礼乔",
                                 "王超峰",
                                 "赵紫茹",
                                 "佟鹏鲲",
                                 "常玉亮",
                                 "李旭阳",
                                 "潘恩哲",
                                 "张志强",
                                 "陈安然",
                                 "景磊",
                                 "陈远涛",
                                 "汪磊",
                                 "徐居乐",
                                 "张勐",
                                 "朱汉青",
                                 "闫凯旋",
                                 "路欣宇",
                                 "王鹏飞",
                                 "郭旭",
                                 "顾士亮",
                                 "陈梦豪",
                                 "赵磊",
                                 "赵大鹏",
                                 "纪纲",
                                 "魏彦楠",
                                 "贺洋洋",
                                 "钱成",
                                 "胡硕",
                                 "李晶莹",
                                 "张敬涛",
                                 "徐敏",
                                 "孟响",
                                 "王仕浩",
                                 "娄世起",
                                 "侯海星",
                                 "王蔚深",
                                 "王伟梁",
                                 "周昕卓",
                                 "姜浩楠",
                               };
};

#endif
