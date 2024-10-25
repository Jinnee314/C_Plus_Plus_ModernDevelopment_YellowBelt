#pragma once
#include <map>
#include <string>
#include <tuple>

enum class TaskStatus
{
	NEW,
	IN_PROGRESS,
	TESTING,
	DONE
};

using TasksInfo = std::map<TaskStatus, int>;

class TeamTask
{
private:
	std::map<std::string, TasksInfo> allPerson;

public:
	const TasksInfo& GetPersonTasksInfo(const std::string& person) const;
	
	void AddNewTask(const std::string& person);

	std::tuple<TasksInfo, TasksInfo> PerformPersonTasks
	(
		const std::string& person, int task_count
	);
};

