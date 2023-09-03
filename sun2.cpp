#include <iostream>
#include <regex>
#include <set>

int countUniqueDDDates(const std::string& str) {
    std::regex dateRegex(R"(\b(\d{2})-(\d{2})-(\d{4})\b)"); // 正则表达式匹配日期格式
    std::set<std::string> uniqueDDDates; // 使用set来存储不同的DD日期

    std::smatch match;
    std::string::const_iterator searchStart(str.cbegin());

    while (std::regex_search(searchStart, str.cend(), match, dateRegex)) {
        if (match.size() == 4) {
            uniqueDDDates.insert(match[1].str()); // 提取DD部分并加入set
            searchStart = match.suffix().first; // 更新搜索起点
        }
    }

    return uniqueDDDates.size();
}

int main() {
    std::string str = "Some text with dates: 12-05-2023, 24-09-2023, 12-05-2023, 15-08-2023";
    int uniqueDDCount = countUniqueDDDates(str);
    std::cout << "不同的DD日期个数: " << uniqueDDCount << std::endl;

    return 0;
}
