#pragma once
#include "pch.h"
#include "quiz.h"
#include "quiz_10grade.h"

// Function to find a student by name in the Scores.txt file
bool findStudent(const std::string& name, student currentStudent);

void updateStudent(const student currentStudent);


