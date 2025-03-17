#pragma once

template <typename T>
class UniquePtr {
private:
	T* myPtr;

public:
	explicit UniquePtr(T* inputPtr = nullptr) noexcept : myPtr(inputPtr) {}

	UniquePtr(const UniquePtr&) = delete;
	UniquePtr& operator=(const UniquePtr&) = delete;

	T& operator*() const noexcept { return *myPtr; }
	T& operator->() const noexcept { return myPtr; }

	T* release() noexcept {
		T* temp = myPtr;
		myPtr = nullptr;
		return temp;
	}

	~UniquePtr() { delete myPtr; };
};