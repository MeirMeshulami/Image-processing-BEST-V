#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "./ui_mainwindow.h"
#include "custom/CheckComboBox.h"
#include "custom/flowlayout.h"
#include "JsonManager.h"
#include "settings.h"

#include <cctv/core.h>
#include <opencv2/opencv.hpp>
#include <QLayout>
#include <QMainWindow>
#include <QMouseEvent>
#include <QPoint>
#include <QRect>
#include <QStyle>
#include <QtGui>
#include <QWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

protected:
	void mousePressEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
	QString findLatestLogFile(const QString& folderPath);
	void updateLogTextBrowser();
	void loadLogFolderPath();
	void loadConfigs();
	void loadComboBoxClasses();
	bool eventFilter(QObject* obj, QEvent* event)override;
	std::string getServerAddress();
public:
	MainWindow(QWidget* parent = nullptr);
	~MainWindow();

signals:
	void frameReady(const cv::Mat& frame);

private slots:

	void on_homeBtn_clicked();

	void on_dataAnalBtn_clicked();

	void on_reportBtn_clicked();

	void on_exit_clicked();

	void on_refreshBtn_clicked();

	void on_extend_clicked();

	void on_minimize_clicked();

	void on_cleareBtn_clicked();

	void on_liveBtn_clicked();

	void on_SettingsBtn_clicked();

	void on_showLogsBtn_clicked();

	void on_browseLogsBtn_clicked();

	void refreshLogContent();

	void on_InformationBtn_clicked();

	void init();

	void deInit();

	void on_accountBtn_clicked();

	void on_appBtn_clicked();

	void on_feautersBtn_clicked();

	void on_editName_clicked();

	void on_userBtn_clicked();

	void on_stopLiveBtn_clicked();

	void on_threasholdSlider_valueChanged(int value);

	void display_capture_imgs(const QString& folderPath);

	void on_browseCapBtn_clicked();

	void modifyClassList(const std::string className, bool isChecked);

	void on_detectCheck_stateChanged(int arg1);

	void on_fpsCheck_stateChanged(int arg1);

	void pollFramesForDisplay();

	void displayFrame(const cv::Mat& frame);

	void on_applyBtn_clicked();

private:
	Ui::MainWindow* ui;
	bool m_dragging;
	QPoint m_dragStartPosition;
	QPoint m_dragLastPosition;
	std::atomic<bool> isLive;
	API api;
	QThread* frameDisplayThread;
	QString logFolderPath;
	QString currentLogFilePath;
	bool isBrowsingLogFile;
	QString CaptureImgFolderPath;
	nlohmann::json configs;
	bool detection = false;
	bool displayFps = false;
};

#endif // MAINWINDOW_H