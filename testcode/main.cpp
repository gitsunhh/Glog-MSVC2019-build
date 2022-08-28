#define GLOG_NO_ABBREVIATED_SEVERITIES
#define GLOG_CUSTOM_PREFIX_SUPPORT
#define NOMINMAX
#include <glog/logging.h>
#include <iostream>
#include <vector>
#include <iomanip>
#define WRITE_LOG(s) (LOG(INFO)<<s)

using namespace std;

void CustomPrefix(std::ostream &s, const google::LogMessageInfo &l, void*) {
	s << l.severity[0]
		<< setw(4) << 1900 + l.time.year() << "-"
		<< setw(2) << 1 + l.time.month() << "-"
		<< setw(2) << l.time.day()
		<< ' '
		<< setw(2) << l.time.hour() << ':'
		<< setw(2) << l.time.min() << ':'
		<< setw(2) << l.time.sec() << "."
		<< setw(6) << l.time.usec()
		<< ' '
		<< setfill(' ') << setw(5)
		<< l.thread_id << setfill('0')
		<< ' '
		<< l.filename << ':' << l.line_number << "]";
}


int main(int argc, char * argv[])
{
	FLAGS_log_dir = ".";
	google::SetLogFilenameExtension(".log");
	//google::InitGoogleLogging("AlgLog");
	google::InitGoogleLogging("AlgLog", &CustomPrefix);
	WRITE_LOG("google initial log");
	google::FlushLogFiles(google::GLOG_INFO);
	LOG_EVERY_T(INFO, 0.10) << "haha";
	for (int i = 0; i < 101; ++i)
	{
		LOG_IF(INFO, i > 90) << "it's " << i << "th loop.";
		LOG_EVERY_N(INFO, 5) << "it's " << i << "th loop.";
		LOG_IF_EVERY_N(INFO, i > 90, 3) << "it's " << i << "th loop.";
	}

	google::ShutdownGoogleLogging();
	system("pause");
	return EXIT_SUCCESS;
}
