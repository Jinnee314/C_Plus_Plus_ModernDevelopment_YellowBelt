#include <iostream>
#include <map>
#include <string>

template<typename Key, typename Value>
Value& GetRefStrict(std::map<Key, Value>& m, const Key& key)
{
	if (!m.contains(key))
	{
		throw std::runtime_error("Element doesn't exist;");
	}

	auto& elem = m.at(key);

	return elem;
}

int main()
{
	std::map<int, std::string> m = { {0, "value"} };
	auto& item = GetRefStrict(m, 0);
	item = "newvalue";
	std::cout << m[0] << std::endl;

	return 0;
}