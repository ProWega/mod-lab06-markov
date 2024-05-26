// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include "textgen.h"

// ��������������� ������� ��� ������ ������� ���������
void print_statetab() {
    for (const auto &entry : statetab) {
        for (const auto &word : entry.first) {
            std::cout << word << " ";
        }
        std::cout << ": ";
        for (const auto &suffix : entry.second) {
            std::cout << suffix << " ";
        }
        std::cout << std::endl;
    }
}

// ���� 1: ������������ �������� �� ��������� ����� ����
TEST(TextGenTest, PrefixGeneration) {
    // ������� �������
    statetab.clear();
    
    // ������ ��������� �����
    std::ofstream test_file("test_input.txt");
    test_file << "�����1 �����2 �����3 �����4 �����5";
    test_file.close();

    // �������� ��� NPREF = 2
    build("test_input.txt", 2);
    ASSERT_EQ(statetab.size(), 3);
    ASSERT_EQ(statetab[prefix({"�����1", "�����2"})], std::vector<std::string>({"�����3"}));
    ASSERT_EQ(statetab[prefix({"�����2", "�����3"})], std::vector<std::string>({"�����4"}));
    ASSERT_EQ(statetab[prefix({"�����3", "�����4"})], std::vector<std::string>({"�����5"}));

    // ������� �������
    statetab.clear();

    // �������� ��� NPREF = 3
    build("test_input.txt", 3);
    ASSERT_EQ(statetab.size(), 2);
    ASSERT_EQ(statetab[prefix({"�����1", "�����2", "�����3"})], std::vector<std::string>({"�����4"}));
    ASSERT_EQ(statetab[prefix({"�����2", "�����3", "�����4"})], std::vector<std::string>({"�����5"}));
}

// ���� 2: ������������ ������ "�������-�������"
TEST(TextGenTest, PrefixSuffixRecord) {
    statetab.clear();
    prefix pref = {"�����1", "�����2"};
    statetab[pref].push_back("�����3");
    ASSERT_EQ(statetab[pref].size(), 1);
    ASSERT_EQ(statetab[pref][0], "�����3");
}

// ���� 3: ����� ������������� �������� �� �������
TEST(TextGenTest, SingleSuffixSelection) {
    statetab.clear();
    prefix pref = {"�����1", "�����2"};
    statetab[pref].push_back("�����3");
    std::string next_word = statetab[pref][0];
    ASSERT_EQ(next_word, "�����3");
}

// ���� 4: ����� �������� �� �������, ����������� ��������� ���������
TEST(TextGenTest, MultipleSuffixSelection) {
    statetab.clear();
    prefix pref = {"�����1", "�����2"};
    statetab[pref] = {"�����3", "�����4", "�����5"};
    ASSERT_EQ(statetab[pref].size(), 3);
}

// ���� 5: ������������ ������ �������� �����
TEST(TextGenTest, TextGeneration) {
    // ������� � ���������� ������� �������
    statetab.clear();
    prefix pref1 = {"�����1", "�����2"};
    statetab[pref1].push_back("�����3");
    prefix pref2 = {"�����2", "�����3"};
    statetab[pref2].push_back("�����4");
    prefix pref3 = {"�����3", "�����4"};
    statetab[pref3].push_back("�����5");

    std::string text = generate_text(5);
    std::cout << "Generated text: " << text << std::endl;
    ASSERT_FALSE(text.empty());
}