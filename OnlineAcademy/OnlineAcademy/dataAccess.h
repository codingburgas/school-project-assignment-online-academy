#pragma once
#include "pch.h"
#include "quiz.h"
#include "quiz_10grade.h"

// Function to find a student by name in the Scores.txt file
bool findStudent(const std::string& name, student currentStudent);

// Function to update a student's score in the Scores.txt file
void updateStudent(const student currentStudent);


