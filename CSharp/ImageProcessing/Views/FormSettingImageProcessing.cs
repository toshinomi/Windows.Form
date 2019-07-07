using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ImageProcessing.Views
{
    public partial class FormSettingImageProcessing : Form
    {
        private List<ComImageProcessingType> m_items;

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

            cmbBoxImageProcessingType.Items.Add(m_items);
            cmbBoxImageProcessingType.SelectedIndex = (int)m_items.Find(x => x.Name == Properties.Settings.Default.ImgTypeEdgeName)?.Id - 1;

            return;
        }

        public void SaveParam()
        {
            ComImageProcessingType imgProcType = (ComImageProcessingType)cmbBoxImageProcessingType.SelectedItem;
            Properties.Settings.Default.ImgTypeSelectName = imgProcType.Name;
            Properties.Settings.Default.Save();

            return;
        }

        private void OnClickOk(object sender, EventArgs e)
        {
            SaveParam();
        }

        private void OnClickCancel(object sender, EventArgs e)
        {
            Close();
        }
    }
}