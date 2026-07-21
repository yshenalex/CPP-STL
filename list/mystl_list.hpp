#pragma once
#include <iostream>
#include <cassert>
namespace mystl
{

	/**
	 * @brief list的结点
	 * 
	 * @tparam T 结点元素类型
	 */
	template <class T>
	struct __list_node
	{
		/**
		 * @brief 前驱结点指针
		 * 
		 */
		__list_node<T> *_next;

		/**
		 * @brief 后继结点指针
		 * 
		 */
		__list_node<T> *_prev;

		/**
		 * @brief 结点存储元素值
		 * 
		 */
		T _val;

		__list_node(const T &x = T())
			: _next(nullptr), _prev(nullptr), _val(x)
		{
		}
	};

	/**
	 * @brief 迭代器
	 * 
	 * @tparam T 结点元素类型
	 * @tparam Ref 结点元素的引用
	 * @tparam Ptr 结点元素的指针
	 */
	template <class T, class Ref, class Ptr>
	struct __list_iterator
	{
		typedef __list_node<T> Node;
		typedef __list_iterator<T, Ref, Ptr> Self;
		Node *_node;

		__list_iterator(Node *node = nullptr) // 复制构造函数名字一定要是类名，不能是重命名后的名字Self
			: _node(node)
		{
		}

		/**
		 * @brief 判断是否 不是同一迭代器节点
		 * 
		 * @param l 
		 * @return true 
		 * @return false 
		 */
		bool operator!=(const Self &l) const
		// 提问：括号内为什么要加const?个思：因为this指针本质是*const 类型，
		// 而将两个元素进行比较的前提是类型要相同，因此也必须为const对象，
		// 否则使用时编译器会匹配不到而报错
		{
			return _node != l._node;
		}

		/**
		 * @brief 判断是否是同一迭代器节点
		 * 
		 * @param l 
		 * @return true 
		 * @return false 
		 */
		bool operator==(const Self &l) const
		{
			return _node == l._node;
		}

		/**
		 * @brief 迭代器前置++
		 * 
		 * @return Self& 
		 */
		Self &operator++()
		{
			_node = _node->_next;
			return *this;
		}

		/**
		 * @brief 迭代器后置++操作
		 * 
		 * @return Self 
		 */
		Self operator++(int)
		{
			// Self tmp(*this);
			Self *tmp = this;
			_node = _node->_next;

			// return tmp;
			return *tmp;
		}

		/**
		 * @brief 迭代器前置--操作
		 * 
		 * @return Self& 
		 */
		Self &operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		/**
		 * @brief 迭代器后置--操作
		 * 
		 * @return Self 
		 */
		Self operator--(int)
		{
			Self *tmp = this;
			_node = _node->_prev;
			return *tmp;
		}

		/**
		 * @brief 结点解引用
		 * 
		 * @return Ref 得到结点存储的val数值的引用
		 */
		Ref operator*()
		{
			return _node->_val;
		}

		/**
		 * @brief 结点存储的val的地址
		 * 
		 * @return Ptr 结点存储的val的地址
		 */
		Ptr operator->()
		{
			return &_node->_val;
		}
	};

	/**
	 * @brief 模拟实现stl的list
	 * 
	 * @tparam _Tp list结点存储数据类型
	 */
	template <class _Tp>
	class list
	{
	private:
		/**
		 * @brief list结点
		 * 
		 */
		typedef __list_node<_Tp> Node;

	public:
		/**
		 * @brief 迭代器
		 * 
		 */
		typedef __list_iterator<_Tp, _Tp &, _Tp *> iterator;
		/**
		 * @brief const迭代器
		 * 
		 */
		typedef __list_iterator<_Tp, const _Tp &, const _Tp *> const_iterator;

	public:
		/**
		 * @brief 创建一个新的list对象
		 * 
		 */
		list();

		/**
		 * @brief 创建一个新的list对象
		 * 
		 * @param n 需要的初始元素个数
		 * @param x 初始存储的元素值
		 */
		list(int n, const _Tp &x);

		/**
		 * @brief 复制构造函数
		 * 
		 * @param lt 被复制的list对象
		 */
		list(const list<_Tp> &lt);

		/**
		 * @brief 赋值运算符重载
		 * 
		 * @param lt 需要赋值给当前对象的原list对象
		 * @return list<_Tp>& 当前对象经赋值操作后新的引用
		 */
		list<_Tp> &operator=(const list<_Tp> lt);

		/**
		 * @brief 获取list起始结点的迭代器
		 * 
		 * @return iterator 迭代器
		 */
		iterator begin();

		/**
		 * @brief 获取list起始结点的const迭代器
		 * 
		 * @return const_iterator const迭代器
		 */
		const_iterator begin() const;

		/**
		 * @brief 哨兵节点的迭代器
		 * 
		 * @return iterator 
		 */
		iterator end();

		/**
		 * @brief 哨兵节点的const迭代器
		 * 
		 * @return const_iterator 
		 */
		const_iterator end() const;

		/**
		 * @brief 尾插
		 * 
		 * @param x 需要插入进list的对象
		 */
		void push_back(const _Tp &x);

		/**
		 * @brief 头插
		 * 
		 * @param x 需要插入进list的对象
		 */
		void push_front(const _Tp &x);

		/**
		 * @brief 尾删
		 * 
		 */
		void pop_back();

		/**
		 * @brief 头删
		 * 
		 */
		void pop_front();

		/**
		 * @brief 在pos位置插入
		 * 
		 * @param pos 插入位置的迭代器
		 * @param x 需要插入进list的对象
		 * @return iterator 插入后的元素的迭代器
		 */
		iterator insert(iterator pos, const _Tp &x);

		/**
		 * @brief 删除pos位置的元素
		 * 
		 * @param pos 需要删除的位置的迭代器
		 * @return iterator 
		 */
		iterator erase(iterator pos);

		/**
		 * @brief list是否为空
		 * 
		 * @return true 空
		 * @return false 非空
		 */
		bool empty() const;

		/**
		 * @brief 清除list所有节点对象
		 * 
		 */
		void clear();

		/**
		 * @brief 销毁list对象
		 * 
		 */
		~list();

	private:
		/**
		 * @brief list的哨兵节点
		 * 
	 	*/
		Node *_head;
	};

	template <class _Tp>
	list<_Tp>::list()
	{
		_head = new Node;
		_head->_next = _head;
		_head->_prev = _head;
	}

	template <class _Tp>
	list<_Tp>::list(int n, const _Tp &x)
	{
		_head = new Node;
		_head->_next = _head;
		_head->_prev = _head;

		for (int i = 0; i < n; i++)
			push_back(x);
	}

	template <class _Tp>
	list<_Tp>::list(const list<_Tp> &lt)
	{
		_head = new Node();
		_head->_next = _head;
		_head->_prev = _head;

		const_iterator it = lt.begin();
		while (it != lt.end())
		{
			push_back(*it);
			it++;
		}

		// 当然也可以用范围for, 支持迭代器就支持范围for:
		// for (auto e : lt)
		//	push_back(e);
	}

	template <class _Tp>
	list<_Tp> &list<_Tp>::operator=(const list<_Tp> lt)
	{
		std::swap(_head, lt._head);
		return *this;
	}

	/*
		//【复制运算符重载的另一种实现方式】：
		template <class _Tp>
		list<_Tp> &list<_Tp>::operator=(const list<_Tp> &lt)
		{
			if (*this != &lt)
			{
				clear();
				const_iterator it = lt.begin();
				while (it != lt.end())
				{
					push_back(*it);
					it++;
				}
			}
		}
	*/
	template <class _Tp>
	typename list<_Tp>::iterator list<_Tp>::begin()
	{
		return iterator(_head->_next);
	}

	template <class _Tp>
	typename list<_Tp>::const_iterator list<_Tp>::begin() const
	{
		return const_iterator(_head->_next);
	}

	template <class _Tp>
	typename list<_Tp>::iterator list<_Tp>::end()
	{
		return iterator(_head);
	}

	template <class _Tp>
	typename list<_Tp>::const_iterator list<_Tp>::end() const
	{
		return const_iterator(_head);
	}
	template <class _Tp>
	void list<_Tp>::push_back(const _Tp &x)
	{
		/*
			//【单独实现或调用insert都可以】:
			Node* newnode = new Node(x);
			Node* tail = _head->_prev;

			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;
		*/
		insert(end(), x);
	}
	template <class _Tp>
	void list<_Tp>::push_front(const _Tp &x)
	{
		insert(begin(), x);
	}

	template <class _Tp>
	void list<_Tp>::pop_back()
	{
		erase(--end());
	}

	template <class _Tp>
	void list<_Tp>::pop_front()
	{
		erase(begin());
	}

	template <class _Tp>
	typename list<_Tp>::iterator list<_Tp>::insert(iterator pos, const _Tp &x)
	{
		Node *newnode = new Node(x);
		Node *prev = pos._node->_prev;
		Node *cur = pos._node;

		prev->_next = newnode;
		newnode->_prev = prev;
		newnode->_next = cur;
		cur->_prev = newnode;

		return iterator(newnode); // 在pos位置之前插入一个元素，返回新元素节点(pos上一个节点)
	}

	template <class _Tp>
	typename list<_Tp>::iterator list<_Tp>::erase(typename list<_Tp>::iterator pos)
	{
		assert(pos != end());

		Node *prev = pos._node->_prev;
		Node *next = pos._node->_next;

		prev->_next = next;
		next->_prev = prev;

		delete pos._node;

		return iterator(next);
	}

	template <class _Tp>
	bool list<_Tp>::empty() const
	{
		return _head == _head->_next;
	}

	template <class _Tp>
	void list<_Tp>::clear()
	{
		iterator it = begin();
		while (it != end())
		{
			it = erase(it);
		}
	}

	template <class _Tp>
	list<_Tp>::~list()
	{
		clear();
		delete _head;
		_head = nullptr;
	}

}
