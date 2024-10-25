#pragma once
#include <string>
#include <memory>

#include "Date.hpp"

enum class Comparison {
	Less,
	LessOrEqual,
	Greater,
	GreaterOrEqual,
	Equal,
	NotEqual
};

enum class LogicalOperation
{
	Or, And
};

class Node
{
public:
	virtual bool Evaluate(const Date& date, const std::string& event) const = 0;
};

class EmptyNode :
	public Node
{
	virtual bool Evaluate(const Date& date, const std::string& event) const override;
};

class DateComparisonNode :
	public Node
{
private:
	Comparison cmp;
	Date date;

public:
	DateComparisonNode(Comparison cmp, const Date& date);

	bool Evaluate(const Date& date, const std::string& event) const override;
};

class EventComparisonNode :
	public Node
{
private:
	Comparison cmp;
	std::string ev;

public:
	EventComparisonNode(Comparison cmp, const std::string& ev);

	bool Evaluate(const Date& date, const std::string& event) const override;
};

class LogicalOperationNode :
	public Node
{
private:
	LogicalOperation logOp;
	std::shared_ptr<Node> left, right;

public:
	LogicalOperationNode(
		LogicalOperation logOp, 
		const std::shared_ptr<Node>& left, 
		const std::shared_ptr<Node>& right
	);

	bool Evaluate(const Date& date, const std::string& event) const override;
};

