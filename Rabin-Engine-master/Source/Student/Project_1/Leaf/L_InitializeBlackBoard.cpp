#include <pch.h>
#include "L_InitializeBlackBoard.h"

void L_InitializeBlackBoard::on_enter()
{
	auto& bb = agent->get_blackboard();

	//bb.set_value<const char*>("AgentName", "Agent");
	//bb.set_value<Agent*>("Target", nullptr);
	//bb.set_value<Agent*>("Ideal Match", nullptr);
	bb.set_value<int>("KeyPressed", -1);
	bb.set_value<float>("Speed", 2.0f);
	bb.set_value<int>("LastActiveNode", 10);

	on_success();

	display_leaf_text();
}