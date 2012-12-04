CMAKE_MINIMUM_REQUIRED (VERSION 2.6) 
PROJECT (dboperators)

add_definitions("-O3") 

# the join operators
ADD_EXECUTABLE ( nested_loop_join.o join_main.cpp NestedLoopJoin.cpp )
ADD_EXECUTABLE ( hash_join.o join_main.cpp HashJoin.cpp )
ADD_EXECUTABLE ( sort_merge_join.o join_main.cpp SortMergeJoin.cpp )
SET_TARGET_PROPERTIES(nested_loop_join.o PROPERTIES COMPILE_FLAGS "-DNESTEDLOOPJOIN")
SET_TARGET_PROPERTIES(hash_join.o PROPERTIES COMPILE_FLAGS "-DHASHJOIN")
SET_TARGET_PROPERTIES(sort_merge_join.o PROPERTIES COMPILE_FLAGS "-DSORTMERGEJOIN")

# the group operators
ADD_EXECUTABLE ( nested_loop_group.o group_main.cpp NestedLoopGroup.cpp )
ADD_EXECUTABLE ( hash_group.o group_main.cpp HashGroup.cpp )
ADD_EXECUTABLE ( sort_merge_group.o group_main.cpp SortMergeGroup.cpp )
SET_TARGET_PROPERTIES(nested_loop_group.o PROPERTIES COMPILE_FLAGS "-DNESTEDLOOPGROUP")
SET_TARGET_PROPERTIES(hash_group.o PROPERTIES COMPILE_FLAGS "-DHASHGROUP")
SET_TARGET_PROPERTIES(sort_merge_group.o PROPERTIES COMPILE_FLAGS "-DSORTMERGEGROUP")
