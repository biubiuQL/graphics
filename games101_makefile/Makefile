.PHONY:pre debug objs exe run lib

debug:
	$(info ${main_name})

IS_DEBUG:=ture

own:=false

#入口函数所在脚本名
main_name=Main/Work1

ifeq (${own},false)
main_name=Reference/Work1
endif

include:=\
-I "./Framework/opencv/build/include/opencv2"\
-I "./Framework/opencv/build/include"\
-I "./Framework/eigen-3.4.0"

library:=\
-l "libopencv_calib3d490"\
-l "libopencv_core490"\
-l "libopencv_dnn490"\
-l "libopencv_features2d490"\
-l "libopencv_flann490"\
-l "libopencv_highgui490"\
-l "libopencv_imgcodecs490"\
-l "libopencv_imgproc490"\
-l "libopencv_ml490"\
-l "libopencv_objdetect490"\
-l "libopencv_photo490"\
-l "libopencv_stitching490"\
-l "libopencv_video490"\
-l "libopencv_videoio490"\

exe_cmd:=@g++ ${main_name}.cpp ${include} -L "C:\\Program Files\\mingw64\\lib" ${library} -o ${main_name}.exe
ifeq (${IS_DEBUG},ture) 
exe_cmd+=-g
endif
exe:
	${exe_cmd}


run:exe
	@./${main_name}.exe