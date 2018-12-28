#include "Failure.h"

Failure::Failure(
    const std::string& theCondition,
    const std::string& theFileName,
    long theLineNumber)
    : condition(theCondition),
    fileName(theFileName),
    lineNumber(theLineNumber)
{
}

Failure::Failure(
    const std::wstring& theCondition,
    const std::string& theFileName,
    long theLineNumber)
    : condition(theCondition.begin(), theCondition.end()),
    fileName(theFileName),
    lineNumber(theLineNumber)
{
}

std::ostream& operator<<(
    std::ostream& stream,
    Failure& failure)
{
    stream << std::endl
           << failure.fileName
           << "(" << failure.lineNumber << ") : "
           << "Failure: " << failure.condition;
    return stream;
}
