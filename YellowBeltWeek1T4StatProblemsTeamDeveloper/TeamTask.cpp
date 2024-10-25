#include "TeamTask.h"

const TasksInfo& TeamTask::GetPersonTasksInfo(const std::string& person) const
{
	return allPerson.at(person);
}

void TeamTask::AddNewTask(const std::string& person)
{
	++allPerson[person][TaskStatus::NEW];
}

std::tuple<TasksInfo, TasksInfo> TeamTask::PerformPersonTasks
(
	const std::string& person,
	int taskCount
)
{
	int copyTaskCount = taskCount;

	TasksInfo updatedInfo;
	TasksInfo untouchedInfo;
	TasksInfo resInfo;

	int status = static_cast<int>(TaskStatus::IN_PROGRESS);

	for (const auto& [key, value] : allPerson.at(person))
	{
		if (key != TaskStatus::DONE && value != 0)
		{
			if (value < copyTaskCount)
			{
				updatedInfo[static_cast<TaskStatus>(status)] = value;

				resInfo[static_cast<TaskStatus>(status)] += value;

				copyTaskCount -= value;
				++status;
			}
			else
			{
				if (copyTaskCount)
				{
					updatedInfo[static_cast<TaskStatus>(status)] = copyTaskCount;
					untouchedInfo[key] = value - copyTaskCount;

					resInfo[static_cast<TaskStatus>(status)] += copyTaskCount;
					resInfo[key] += value - copyTaskCount;

					++status;
					copyTaskCount = 0;
				}
				else
				{
					untouchedInfo[key] = value;

					resInfo[key] += value;
				}
			}
		}
	}

	resInfo[TaskStatus::DONE] += allPerson.at(person)[TaskStatus::DONE];

	allPerson[person] = resInfo;

	return { updatedInfo, untouchedInfo };
}

