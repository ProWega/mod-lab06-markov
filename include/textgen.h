// Copyright 2024 UNN-IASR
#ifndef INCLUDE_TEXTGEN_H_
#define INCLUDE_TEXTGEN_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <deque>
#include <map>
#include <vector>
#include <random>
#include <ctime>
#include <string>

// ��������� ��� ���������� ���� � �������� � ������������� ���������� ������������ ����
const int NPREF = 2;
const int MAXGEN = 1000;

// ����������� ���� ��� ��������
typedef std::deque<std::string> prefix;

// ������� ��������� ��� ��������� � ���������
extern std::map<prefix, std::vector<std::string>> statetab;

// ������� ��� ���������� ������� ��������� � ��������� �� �������� �����
void build(const std::string& filename, int NPREF);

// ������� ��� ��������� ������ �������� ����� �� ������ ������� ��������� � ���������
std::string generate_text(int max_words);

#endif  // INCLUDE_TEXTGEN_H_
