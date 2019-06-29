#pragma once

#include <QtWidgets>

class ColorPicker : public QWidget
{
	Q_OBJECT

public:
	ColorPicker(QWidget *parent, QColor color = Qt::black);
	~ColorPicker();
	inline void setColor(QColor);
	inline QColor getColor() const;
private:
	void resizeEvent(QResizeEvent* event) override;
	void updateLabel();

	void sColorDialog(void);

	QColor color;
	QLabel* colorLabel;
	QPushButton* changePB;
};

inline QColor ColorPicker::getColor() const
{
	return color;
}

inline void ColorPicker::setColor(QColor newColor)
{
	color = newColor;
	updateLabel();
}