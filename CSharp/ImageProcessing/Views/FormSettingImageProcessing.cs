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
            var items = new List<ComImageProcessingType>
            {
                new ComImageProcessingType(Properties.Settings.Default.ImageTypeEdgeId, Properties.Settings.Default.ImageTypeEdgeName),
                new ComImageProcessingType(Properties.Settings.Default.ImageTypeGrayScaleId, Properties.Settings.Default.ImageTypeGrayScaleName),
                new ComImageProcessingType(Properties.Settings.Default.ImageTypeBinarizationId, Properties.Settings.Default.ImageTypeBinarizationName),
                new ComImageProcessingType(Properties.Settings.Default.ImageTypeGrayScale2DiffId, Properties.Settings.Default.ImageTypeGrayScale2DiffName),
                new ComImageProcessingType(Properties.Settings.Default.ImageTypeColorReversalId, Properties.Settings.Default.ImageTypeColorReversalName)
            };

            cmbBoxImageProcessingType.Items.Add(Properties.Settings.Default.ImageTypeEdgeName);
            cmbBoxImageProcessingType.Items.Add(Properties.Settings.Default.ImageTypeGrayScaleName);
            cmbBoxImageProcessingType.Items.Add(Properties.Settings.Default.ImageTypeBinarizationName);
            cmbBoxImageProcessingType.Items.Add(Properties.Settings.Default.ImageTypeGrayScale2DiffName);
            cmbBoxImageProcessingType.Items.Add(Properties.Settings.Default.ImageTypeColorReversalName);
            cmbBoxImageProcessingType.SelectedIndex = (int)items.Find(x => x.Name == Properties.Settings.Default.ImageTypeSelectName)?.Id - 1;

            return;
        }

        /// <summary>
        /// 設定の保存
        /// </summary>
        public void SaveParam()
        {
            Properties.Settings.Default.ImageTypeSelectName = (string)cmbBoxImageProcessingType.SelectedItem;
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