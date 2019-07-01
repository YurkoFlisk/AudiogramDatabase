#pragma once

#include <QtCore>

class LanguagesModel : public QAbstractListModel
{
	Q_OBJECT

public:
	struct LanguageInfo
	{
		LanguageInfo(QString code, QString name, QString path)
			: code(code), name(name), path(path)
		{}
		QString code;
		QString name;
		QString path;
	};

	static constexpr Qt::ItemDataRole NameRole = Qt::DisplayRole;
	static constexpr Qt::ItemDataRole CodeRole = Qt::UserRole;
	static constexpr Qt::ItemDataRole PathRole = Qt::ItemDataRole(CodeRole + 1);

	LanguagesModel(QString path, QObject *parent = nullptr);
	~LanguagesModel();
	int rowCount(const QModelIndex& parent = QModelIndex()) const override;
	QVariant data(const QModelIndex& index, int role) const override;
	QString getPathByCode(QString code) const;
	int getRowByCode(QString code) const;
private:
	std::vector<LanguageInfo> elems;
};
