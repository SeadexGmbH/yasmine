$loop(states)	sxy::$var(state_type)& $var(state_name) = $var(region_name).add_$var(state_type)("$var(state_name)", $if(is_composite_state, not)$template(do_behavior.gtpl), $fi$template(enter_behavior.gtpl), $template(exit_behavior.gtpl));
$if(is_composite_state)$template(composite_state.gtpl)$fi$pool
$loop(pseudostates)	sxy::$var(pseudostate_type)& $var(pseudostate_name) = $var(region_name).add_$var(pseudostate_type)("$var(pseudostate_name)");
$pool