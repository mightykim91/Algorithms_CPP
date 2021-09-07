//Merge Sort 

#include <iostream>

using namespace std;

int arr[200] = { 8121, 64103, 88900, 85875, 9207, 8340, 27086, 63184, 6489, 35216, 46608, 16173, 10957, 63620, 56383, 44251, 3482, 64980, 52169, 82735, 92465, 95676, 55285, 12462, 6602, 43694, 82996, 19838, 74925, 40104, 21617, 67748, 85121, 83593, 33874, 32236, 30917, 25686, 20051, 92555, 11942, 99272, 13634, 22834, 3579, 93374, 85525, 68076, 45736, 70747, 31778, 36116, 90884, 98387, 11790, 8383, 13118, 67026, 82628, 4243, 13820, 92155, 91020, 36728, 24264, 22075, 29582, 60954, 49894, 79250, 7612, 49485, 97114, 32299, 78252, 60156, 44560, 66269, 26552, 84598, 742, 97323, 96832, 30672, 5296, 10943, 32546, 33412, 74016, 64221, 40536, 19691, 59333, 46586, 52478, 69442, 99001, 27075, 89234, 24016, 28224, 85433, 78680, 41206, 78836, 41870, 75760, 83079, 15801, 83713, 59605, 43173, 2363, 16958, 30155, 55853, 42954, 22936, 72852, 6254, 57865, 99707, 59929, 46021, 70862, 47863, 95712, 72129, 52013, 41329, 84713, 14010, 28877, 87581, 32310, 89848, 84969, 22770, 28039, 64173, 50709, 62351, 14021, 92727, 74258, 57038, 93531, 68627, 94400, 78901, 23418, 65246, 54833, 26042, 61577, 3606, 85822, 89546, 57853, 52252, 87149, 67527, 50586, 3220, 76902, 4183, 74682, 903, 59747, 91226, 33480, 6202, 3886, 60907, 22138, 66784, 14003, 52758, 17618, 43663, 28684, 82388, 87258, 514, 76413, 51674, 75959, 88580, 42481, 59994, 97686, 26156, 35462, 58227, 96931, 23986, 378, 26469, 22391, 76468 };
int dump[200] = {};

void merge(int left, int right, int mid, int dump[]) {
	for (int i = left; i <= mid; i++) {
		dump[i] = arr[i];
	}
	for (int i = mid + 1; i <= right; i++) {
		dump[i] = arr[i];
	}

	int left_idx = left;
	int right_idx = mid + 1;
	int arr_idx = left;
	while (left_idx <= mid && right_idx <= right) {
		if (dump[left_idx] <= dump[right_idx]) {
			arr[arr_idx] = dump[left_idx];
			left_idx++;
			arr_idx++;
		}
		else {
			arr[arr_idx] = dump[right_idx];
			right_idx++;
			arr_idx++;
		}
	}

	while (left_idx <= mid) {
		arr[arr_idx] = dump[left_idx];
		arr_idx++;
		left_idx++;
	}

	while (right_idx <= right) {
		arr[arr_idx] = dump[right_idx];
		arr_idx++;
		right_idx++;
	}
}

int merge_sort(int left, int right, int dump[]) {
	if (left == right) {
		return 0;
	}
	int mid = (left + right) / 2;
	merge_sort(left, mid, dump);
	merge_sort(mid + 1, right, dump);
	merge(left, right, mid, dump);
}

int main() {
	merge_sort(0, 199, dump);
	for (int i = 0; i < 200; i++) {
		cout << arr[i] << " " << endl;
	}
	return 0;
}