#include "AOIService.h"


namespace AOIService
{
	AOIService::AOIService()
		:_x_root(nullptr)
		,_y_root(nullptr)
	{
	}

	AOIService::~AOIService()
	{
	}

	void AOIService::addNode(IAOINode* node)
	{
		if (node == nullptr) return;

		if (_x_root == nullptr)
		{
			_x_root = node;
			return;
		}

		auto parent_node = _x_root;
		while (parent_node != nullptr)
		{
			if (parent_node->positionX() > node->positionX())
			{
				auto forward_node = parent_node->getXForwardNode();
				if (forward_node != nullptr)
				{
					forward_node->setXBackwardNode(node);
				}

				parent_node->setXForwardNode(node);
				node->setXForwardNode(forward_node);
				node->setXBackwardNode(parent_node);
				break;
			}

			auto backward_node = parent_node->getXBackwardNode();
			if (backward_node == nullptr)
			{
				parent_node->setXBackwardNode(node);
				node->setXForwardNode(parent_node);
				break;
			}

			parent_node = backward_node;
		}

		if (_x_root == nullptr)
		{
			_x_root = node;
			return;
		}

		parent_node = _y_root;
		while (parent_node != nullptr)
		{
			if (parent_node->positionY() > node->positionY())
			{
				auto forward_node = parent_node->getYForwardNode();
				if (forward_node != nullptr)
				{
					forward_node->setYBackwardNode(node);
				}

				parent_node->setYForwardNode(node);
				node->setYForwardNode(forward_node);
				node->setYBackwardNode(parent_node);
				break;
			}

			auto backward_node = parent_node->getYBackwardNode();
			if (backward_node == nullptr)
			{
				parent_node->setYBackwardNode(node);
				node->setYForwardNode(parent_node);
				break;
			}

			parent_node = backward_node;
		}
	}

	void AOIService::removeNode(IAOINode* node)
	{
		if (node == nullptr || _x_root == nullptr) return;

		auto forward_node = node->getXBackwardNode();
		auto backward_node = node->getXForwardNode();

		if (forward_node != nullptr)
		{
			forward_node->setXBackwardNode(backward_node);
		}
		if (backward_node == nullptr)
		{
			backward_node->setXForwardNode(forward_node);
		}

		forward_node = node->getYBackwardNode();
		backward_node = node->getYForwardNode();

		if (forward_node != nullptr)
		{
			forward_node->setYBackwardNode(backward_node);
		}
		if (backward_node == nullptr)
		{
			backward_node->setYForwardNode(forward_node);
		}
	}

	void AOIService::updateAOI(IAOINode* node)
	{
		if (node == nullptr) return;

		removeNode(node);

		auto x_forward_node = node->getXForwardNode();
		while (x_forward_node != nullptr)
		{
			if (x_forward_node->positionX() < node->positionX())
			{
				auto backward_temp_node = x_forward_node->getXBackwardNode();
				if (backward_temp_node != nullptr)
				{
					backward_temp_node->setXForwardNode(node);
				}

				x_forward_node->setXBackwardNode(node);
				node->setXForwardNode(x_forward_node);
				node->setXBackwardNode(backward_temp_node);

				break;
			}

			x_forward_node = x_forward_node->getXForwardNode();
		}
		auto x_backward_node = node->getXBackwardNode();
		while (x_backward_node != nullptr)
		{
			if (x_backward_node->positionX() > node->positionX())
			{
				auto forward_temp_node = x_backward_node->getXForwardNode();
				if (forward_temp_node != nullptr)
				{
					forward_temp_node->setXBackwardNode(node);
				}

				node->setXForwardNode(forward_temp_node);
				node->setXBackwardNode(x_backward_node);
				x_backward_node->setXForwardNode(node);

				break;
			}

			x_backward_node = x_backward_node->getXBackwardNode();
		}

		auto y_forward_node = node->getXForwardNode();
		while (y_forward_node != nullptr)
		{
			if (y_forward_node->positionX() < node->positionX())
			{
				auto backward_temp_node = y_forward_node->getXBackwardNode();
				if (backward_temp_node != nullptr)
				{
					backward_temp_node->setXForwardNode(node);
				}

				y_forward_node->setXBackwardNode(node);
				node->setXForwardNode(y_forward_node);
				node->setXBackwardNode(backward_temp_node);

				break;
			}

			y_forward_node = y_forward_node->getXForwardNode();
		}
		auto y_backward_node = node->getXBackwardNode();
		while (y_backward_node != nullptr)
		{
			if (y_backward_node->positionX() > node->positionX())
			{
				auto forward_temp_node = y_backward_node->getXForwardNode();
				if (forward_temp_node != nullptr)
				{
					forward_temp_node->setXBackwardNode(node);
				}

				node->setXForwardNode(forward_temp_node);
				node->setXBackwardNode(y_backward_node);
				y_backward_node->setXForwardNode(node);

				break;
			}

			y_backward_node = y_backward_node->getXBackwardNode();
		}
	}

	void AOIService::listNodeInRange(AOINodeVector& node_vect, IAOINode* center_node, int range)
	{
		if (center_node == nullptr) return;

		auto x_forward_node = center_node->getXForwardNode();
		auto x_backward_node = center_node->getXBackwardNode();
		auto y_forward_node = center_node->getYForwardNode();
		auto y_backward_node = center_node->getYBackwardNode();

		while (true)
		{
			auto size = node_vect.size();

			if (x_forward_node != nullptr && center_node->isInRange(x_forward_node, range))
			{
				node_vect.push_back(x_forward_node);
				x_forward_node = x_forward_node->getXForwardNode();
			}
			if (x_backward_node != nullptr && center_node->isInRange(x_backward_node, range))
			{
				node_vect.push_back(x_backward_node);
				x_backward_node->getXBackwardNode();
			}
			if (y_forward_node != nullptr && center_node->isInRange(y_forward_node, range))
			{
				node_vect.push_back(y_forward_node);
				y_forward_node = y_forward_node->getYForwardNode();
			}
			if (y_backward_node != nullptr && center_node->isInRange(y_backward_node, range))
			{
				node_vect.push_back(y_backward_node);
				y_backward_node = y_backward_node->getYBackwardNode();
			}

			if (size >= node_vect.size()) break;
		}
	}
}
