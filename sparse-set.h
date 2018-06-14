#include "headers.h"

template <typename t>
class SparseSet
{
	static_assert(is_unsigned<t>::value, "SparseSet can only contain unsigned integers");

  private:
	vector<t> dense;
	vector<t> sparse;

	size_t size_ = 0;
	size_t capacity_ = 0;

  public:
	using iterator = typename vector<t>::const_iterator;
	using const_iterator = typename vector<t>::const_iterator;

	iterator begin()
	{
		return dense.begin();
	}

	const_iterator begin() const
	{
		return dense.begin();
	}

	iterator end()
	{
		return dense.begin() + size_;
	}

	const_iterator end() const
	{
		return dense.begin() + size_;
	}

	size_t size() const
	{
		return size_;
	}

	size_t capacity() const
	{
		return capacity_;
	}

	bool empty() const
	{
		return size_ == 0;
	}

	void clear()
	{
		size_ = 0;
	}

	void reserve(size_t u)
	{
		if (u > capacity_)
		{
			dense.resize(u, 0);
			sparse.resize(u, 0);
			capacity_ = u;
		}
	}

	bool has(const t &val) const
	{
		return val < capacity_ &&
			   sparse[val] < size_ &&
			   dense[sparse[val]] == val;
	}

	void insert(const t &val)
	{
		if (!has(val))
		{
			if (val >= capacity_)
			{
				reserve(val + 1);
			}

			dense[size_] = val;
			sparse[val] = size_;
			++size_;

			cout << endl
				 << val << " has been inserted!";
		}
	}

	void erase(const t &val)
	{
		if (has(val))
		{
			dense[sparse[val]] = dense[size_ - 1];
			sparse[dense[size_ - 1]] = sparse[val];
			--size_;
		}
	}
};