#pragma once

#define TEMPLATE template <class T>

TEMPLATE 
class ArrayList {
	int numElements;
	int capacity;
	T* elements;

public:
	ArrayList() {
		numElements = 0;
		capacity = 1;
		elements = new T[capacity];		
	}

	void insert(T element);
	bool remove(T element);
	bool remove(int index);
	bool set(int index, T data);
	T get(int index);

private:
	void resize();
};

TEMPLATE
void ArrayList<T>::insert(T element) {
	if (numElements == capacity) {
		resize();
	}

	elements[numElements] = element;
	numElements++;
}


TEMPLATE
bool ArrayList<T>::set(int index, T data) {
	if (index < 0 || index > capacity) {
		return false;
	}

	elements[index] = data;
}

TEMPLATE
void ArrayList<T>::resize() {
	T* elementsCpy = new T[capacity];
	int originalCapacity = capacity;

	for (int i = 0; i < capacity; i++) {
		elementsCpy[i] = elements[i];
	}

	capacity *= 2;

	elements = new T[capacity];

	for (int i = 0; i < originalCapacity; i++) {
		elements[i] = elementsCpy[i];
	}
}

TEMPLATE
bool ArrayList<T>::remove(int index) {
	T*elementsCpy = new T[capacity];

	if (index < 0 || index > capacity) {
		return false;
	}


	for (int i = 0; i < numElements; i++) {
		if (i != index) {
			elementsCpy[i] = elements[i];
		}
	}

	numElements--;
	elements = new T[capacity];
	int count = 0;
	
	for (int i = 0; i < numElements; i++) {
		if (i != index) {
			elements[count] = elementsCpy[count];
			count++;

		}
	}

	return true;
}


