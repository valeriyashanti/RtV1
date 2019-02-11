
	t_obj s1;
	s1.dot.x = 0.0;
	s1.dot.y = 0.0;
	s1.dot.z = 0.0 + 2;
	s1.radius = 0.2;
	s1.func = &ray_sphere;
	s1.col.value = 0x0fff00;
	s1.specular = 1.0;
	s1.type = 0;

	t_obj s2;
	s2.dot.x = -0.1;
	s2.dot.y = -0.1;
	s2.dot.z = 3.0;
	s2.radius = 0.3;
	s2.func = &ray_sphere;
	s2.col.value = 0xff00ff;
	s2.specular = 20.0;
	s2.type = 0;

	t_obj cone;
	cone.dot.x = 0.0;    
	cone.dot.y = 0.0;
	cone.dot.z = 4.0;
	cone.col.value = 0x0000ff;
	cone.specular = 0.1;
	cone.reflective = 0.5;
	cone.func = &ray_cone;
	cone.a = 1;
	cone.b = 1.5;
	cone.c = 1;
	cone.type = 0;

	t_obj roll;
	roll.dot.x = 0.000000;    
	roll.dot.y = 0.000000;
	roll.dot.z = 4.000000;
	roll.col.value = 0x0000ff;
	roll.specular = 0.1;
	roll.reflective = 0.5;
	roll.func = &ray_roll;
	roll.a = 0.5;
	roll.b = 1;
	roll.type = 0;

	t_obj pl_left;
	pl_left.radius = -1.000000;
	pl_left.col.value = 0xff0000;
	pl_left.specular = 1.000000;
	pl_left.func = &ray_plane_x;
	pl_left.reflective = 0.500000;
	pl_left.type = 1;

	t_obj pl_right;
	pl_right.radius = 1.000000;
	pl_right.col.value = 0xff00ff;
	pl_right.specular = 0.900000;
	pl_right.func = &ray_plane_x;
	pl_right.type = 1;
	pl_right.reflective = 0.500000;

	t_obj pl_up;
	pl_up.radius = -1.000000;
	pl_up.col.value = 0x00ffff;
	pl_up.specular = 1.500000;
	pl_up.func = &ray_plane_y;
	pl_up.type = 2;
	pl_up.reflective = 0.500000;

	t_obj pl_down;
	pl_down.radius = 1.000000;
	pl_down.type = 2;
	pl_down.col.value = 0xffff00;
	pl_down.specular = 1.1;
	pl_down.func = &ray_plane_y;
	pl_down.reflective = 0.5;

	t_obj plane_z;
	plane_z.radius = 2.000000 + 2;
	plane_z.type = 6;
	plane_z.col.value = 0x0000ff;
	plane_z.specular = 1.100000;
	plane_z.func = &ray_plane_z;
	plane_z.reflective = 0.500000;

	t_obj s_back;	
	s_back.dot.x = -0.1;
	s_back.dot.y = -0.1;
	s_back.dot.z = -4.0;
	s_back.radius = 0.3;
	s_back.func = &ray_sphere;
	s_back.col.value = 0xff00ff;
	s_back.specular = 20.0;
	s_back.type = 0;


// light

	/* rt->light.dot.x = -0.050000;
	rt->light.dot.y = -0.050000;
	rt->light.dot.z = 1.000000;
	rt->light.inten = 0.900000;
 */
	t_obj o;

	rt->objects[0] = s1;
	rt->objects[1] = s2;
	rt->objects[2] = pl_left;
	rt->objects[3] = pl_right;
	rt->objects[4] = pl_up;
	rt->objects[5] = pl_down;
	rt->objects[6] = plane_z;
	rt->objects[7] = s_back;