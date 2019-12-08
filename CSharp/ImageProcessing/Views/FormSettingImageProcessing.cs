using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ImageProcessing
{
    /// <summary>
    /// FormSettingImageProcessing のロジック
    /// </summary>
    public partial class FormSettingImageProcessing : Form
    {
        /// <summary>
        /// 画像処理タイプのコンボボックス
        /// </summary>
        public System.Windows.Forms.ComboBox CmbBoxImageProcessingType
        {
            get { return cmbBoxImageProcessingType; }
        }

        /// <summary>
        /// コンストラクタ
        /// </summary>
        public FormSettingImageProcessing()
        {
            InitializeComponent();

            LoadParam();
        }

        /// <summary>
        /// デスクトラクタ
        /// </summary>
        ~FormSettingImageProcessing()
        {
        }

        /// <summary>
        /// 設定の読込
        /// </summary>
        public void LoadParam()
        {
            List<ComImageProcessingType> items = new List<ComImageProcessingType>();
            items.Add(new ComImageProcessingType(Properties.Settings.Default.ImgTypeEdgeId, Properties.Settings.Default.ImgTypeEdgeName));
            items.Add(new ComImageProcessingType(Properties.Settings.Default.ImgTypeGrayScaleId, Properties.Settings.Default.ImgTypeGrayScaleName));
            items.Add(new ComImageProcessingType(Properties.Settings.Default.ImgTypeBinarizationId, Properties.Settings.Default.ImgTypeBinarizationName));
            items.Add(new ComImageProcessingType(Properties.Settings.Default.ImgTypeGrayScale2DiffId, Properties.Settings.Default.ImgTypeGrayScale2DiffName));
            items.Add(new ComImageProcessingType(Properties.Settings.Default.ImgTypeColorReversalId, Properties.Settings.Default.ImgTypeColorReversalName));

            cmbBoxImageProcessingType.Items.Add(Properties.Settings.Default.ImgTypeEdgeName);
            cmbBoxImageProcessingType.Items.Add(Properties.Settings.Default.ImgTypeGrayScaleName);
            cmbBoxImageProcessingType.Items.Add(Properties.Settings.Default.ImgTypeBinarizationName);
            cmbBoxImageProcessingType.Items.Add(Properties.Settings.Default.ImgTypeGrayScale2DiffName);
            cmbBoxImageProcessingType.Items.Add(Properties.Settings.Default.ImgTypeColorReversalName);
            cmbBoxImageProcessingType.SelectedIndex = (int)items.Find(x => x.Name == Properties.Settings.Default.ImgTypeSelectName)?.Id - 1;

            return;
        }

        /// <summary>
        /// 設定の保存
        /// </summary>
        public void SaveParam()
        {
            Properties.Settings.Default.ImgTypeSelectName = (string)cmbBoxImageProcessingType.SelectedItem;
            Properties.Settings.Default.Save();

            return;
        }

        /// <summary>
        /// OKボタンのクリックイベント
        /// </summary>
        /// <param name="sender">オブジェクト</param>
        /// <param name="e">イベントのデータ</param>
        private void OnClickOk(object sender, EventArgs e)
        {
            SaveParam();
            this.DialogResult = DialogResult.OK;
            Close();
        }

        /// <summary>
        /// Cancelボタンのクリックイベント
        /// </summary>
        /// <param name="sender">オブジェクト</param>
        /// <param name="e">イベントのデータ</param>
        private void OnClickCancel(object sender, EventArgs e)
        {
            this.DialogResult = DialogResult.Cancel;
            Close();
        }
    }
}