#include <pch.h>
#include "D_CheckNearestAlive.h"

void D_CheckNearestAlive::on_enter()
{
	auto& bb = agent->get_blackboard();

	for (auto& t_agent : agents->get_all_agents()) {
		if (agent == t_agent) continue;

		if ((agent->get_position() - t_agent->get_position()).Length() < nearest) {
			nearest = (agent->get_position() - t_agent->get_position()).Length();
			NearestAgent = t_agent;
		}
	}

	BehaviorNode::on_leaf_enter();
}

void D_CheckNearestAlive::on_update(float dt)
{

	if (NearestAgent->get_DOA() == false) {
		on_failure();
	}

	else if (NearestAgent->get_DOA() == true && agent->get_DOA() == true) {
		BehaviorNode* child = children.front();

		child->tick(dt);

		if (child->succeeded() == true)
		{
			on_success();
		}

		else if (child->failed() == true) {
			on_failure();
		}

	}

	display_leaf_text();

}