编译glog
VS2019 + Windows10x64

点击Configure，选择VS2019平台，默认为x64平台。
optional：选中BUILD_SHARED_LIBS，生成动态库
optional：CMAKE_INSTALL_PREFIX改为install目录
点击Configure，一般会出现报错信息：
取消选中 WITH_GFLAGS WITH_UNWIND，（原因：没有安装 gflags 库）
没有报错后，Configure --> Generate --> Open Project

分别在Debug x64和Release x64模式下，右键All_BUILD生成。
然后在Debug x64和Release x64模式下，右键INSTALL生成。