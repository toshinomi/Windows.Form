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
    public partial class FormSettingImageProcessing : Form
    {
        private List<ComImageProcessingType> m_items;

        public System.Windows.Forms.ComboBox CmbBoxImageProcessingType
        {
            get { return cmbBoxImageProcessingType; }
        }

        public FormSettingImageProcessing()
        {
            InitializeComponent();

            LoadParam();
        }

        ~FormSettingImageProcessing()
        {
        }

        public void LoadParam()
        {
            m_items = new List<ComImageProcessingType>();
            m_items.Add(new ComImageProcessingType(Properties.Settings.Default.ImgTypeEdgeId, Properties.Settings.Default.ImgTypeEdgeName));
            m_items.Add(new ComImageProcessingType(Properties.Settings.Default.ImgTypeGrayScaleId, Properties.Settings.Default.ImgTypeGrayScaleName));
            m_items.Add(new ComImageProcessingType(Properties.Settings.Default.ImgTypeBinarizationId, Properties.Settings.Default.ImgTypeBinarizationName));
            m_items.Add(new ComImageProcessingType(Properties.Settings.Default.ImgTypeGrayScale2DiffId, Properties.Settings.Default.ImgTypeGrayScale2DiffName));
            m_items.Add(new ComImageProcessingType(Properties.Settings.Default.ImgTypeColorReversalId, Properties.Settings.Default.ImgTypeColorReversalName));

            cmbBoxImageProcessingType.Items.Add(Properties.Settings.Default.ImgTypeEdgeName);
            cmbBoxImageProcessingType.Items.Add(Properties.Settings.Default.ImgTypeGrayScaleName);
            cmbBoxImageProcessingType.Items.Add(Properties.Settings.Default.ImgTypeBinarizationName);
            cmbBoxImageProcessingType.Items.Add(Properties.Settings.Default.ImgTypeGrayScale2DiffName);
            cmbBoxImageProcessingType.Items.Add(Properties.Settings.Default.ImgTypeColorReversalName);
            cmbBoxImageProcessingType.SelectedIndex = (int)m_items.Find(x => x.Name == Properties.Settings.Default.ImgTypeSelectName)?.Id - 1;

            return;
        }

        public void SaveParam()
        {
            Properties.Settings.Default.ImgTypeSelectName = (string)cmbBoxImageProcessingType.SelectedItem;
            Properties.Settings.Default.Save();

            return;
        }

        private void OnClickOk(object sender, EventArgs e)
        {
            SaveParam();
            this.DialogResult = DialogResult.OK;
            Close();
        }

        private void OnClickCancel(object sender, EventArgs e)
        {
            this.DialogResult = DialogResult.Cancel;
            Close();
        }
    }
}