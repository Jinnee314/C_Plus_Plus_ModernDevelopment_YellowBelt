#include "Node.hpp"

bool EmptyNode::Evaluate(const Date& date, const std::string& event) const
{
	return true;
}

DateComparisonNode::DateComparisonNode(Comparison cmp, const Date& date)
	: cmp(cmp), date(date)
{}

bool DateComparisonNode::Evaluate(const Date& date, const std::string& event) const
{
	switch (cmp)
	{
	case Comparison::Less:
		return date < this->date;
	case Comparison::LessOrEqual:
		return date <= this->date;
	case Comparison::Greater:
		return date > this->date;
	case Comparison::GreaterOrEqual:
		return date >= this->date;
	case Comparison::Equal:
		return date == this->date;
	case Comparison::NotEqual:
		return date != this->date;
	}
}

EventComparisonNode::EventComparisonNode(Comparison cmp, const std::string& ev)
	: cmp(cmp), ev(ev)
{}

bool EventComparisonNode::Evaluate(const Date& date, const std::string& event) const
{
	switch (cmp)
	{
	case Comparison::Less:
		return event < this->ev;
	case Comparison::LessOrEqual:
		return event <= this->ev;
	case Comparison::Greater:
		return event > this->ev;
	case Comparison::GreaterOrEqual:
		return event >= this->ev;
	case Comparison::Equal:
		return event == this->ev;
	case Comparison::NotEqual:
		return event != this->ev;
	}
}

LogicalOperationNode::LogicalOperationNode(
	LogicalOperation logOp,
	const std::shared_ptr<Node>& left,
	const std::shared_ptr<Node>& right
) : logOp(logOp), left(left), right(right)
{}

bool LogicalOperationNode::Evaluate(const Date& date, const std::string& string) const
{
	return logOp == LogicalOperation::And ?
		left->Evaluate(date, string) && right->Evaluate(date, string) :
		left->Evaluate(date, string) || right->Evaluate(date, string);
}