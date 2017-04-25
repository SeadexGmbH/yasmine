$switch(enter_behavior)
$case(0)Y_BEHAVIOR_METHOD2( this, &$var(behavior_class_name)::$var(behavior_method_name) )$esac
$case(1)Y_BEHAVIOR_METHOD2( $var(class_instance_name), &$var(class_instance_name)::$var(behavior_method_name) )$esac
$case(2)Y_BEHAVIOR_METHOD2( &_$var(class_instance_name), &$var(class_instance_name)::$var(behavior_method_name) )$esac
$case(3)Y_BEHAVIOR_FUNCTION2( $var(behavior_method_name) )$esac
$default()Y_EMPTY_BEHAVIOR$tluafed
$hctiws