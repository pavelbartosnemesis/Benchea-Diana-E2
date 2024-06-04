#pragma once
template<typename K, typename V>
class Harta
{
	class lista {
	public:int index;
		K key;
		V value;
		lista() {

		};
		
	};
	lista a[100];
	int i=0;
public:
	void Set(const K key, const V value)
	{
			int ok = 0;
			for (int j = 0; j < i; j++) 
		
				if (a[j].key == key)
				{
					a[j].value=value;
					ok = 1;
				}
			if (!ok)
			{
				a[i].key = key;
				a[i].value = value;
				i++;
			}
	}
	bool Get(const K& key, V& value)
	{
		for (int j = 0; j < i; j++) 
			if (a[j].key == key)
			{
				value = a[j].value;
				return true;
			}
		return false;
	}
	int Count() {
		return i;
	}
	void Clear() {
		for (int j = 0;j < i;j++)
		{
			a[j].key = NULL;
			a[j].index = NULL;
			a[j].value = NULL;

		}
		i = 0;
	}
	bool Delete(const K& key) {
		for (int j = 0; j < i; j++) {
			if (a[j].key == key) 
			{
				for (int x = i + 1; x < a; x++)
					a[x - 1] = a[x];
				return true;
			}
		}
		return false;
	}
};

