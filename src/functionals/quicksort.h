#pragma once
#include <iostream>
#include <vector>

namespace surv {
	// quicksort
	template <typename T>
	void quickSort(std::vector<T>& arr, int left, int right)
	{
		if (left >= right)
			return;
		int i = left, j = right;
		T tmp = arr[left];
		while (i < j)
		{
			while (i < j && arr[j] >= tmp)
				j--;
			if (i < j)
				arr[i++] = arr[j];
			while (i < j && arr[i] <= tmp)
				i++;
			if (i < j)
				arr[j--] = arr[i];
		}
		arr[i] = tmp;
		surv::quickSort(arr, left, i - 1);
		surv::quickSort(arr, i + 1, right);
	}
}
